#include "preview.hxx"

#include <iostream>

namespace TV
{

namespace Editor
{


Preview::Preview ( QWidget *parent, const char *name, WFlags f )
	: QCanvasView ( parent, name, f )
{
	this->setCanvas(new QCanvas(400, 400));
	this->canvas()->setBackgroundColor( Qt::black );

	this->setAcceptDrops(true);

	this->show();

	return;
}
	
Preview::~Preview()
{
	delete this->canvas();
	
	return;
}

void Preview::dropEvent ( QDropEvent *event )
{
	qDebug("dropEvent(): Drop! Target: we@%d:%d | Available Formats:",
		event->pos().x(), event->pos().y(), event->format() );
	
	int n = 0;
	
	while (event->format(n) != 0)
	{
		qDebug("\t%s", event->format(n) );
		n++;
	}


	QImage* image = new QImage();

	if (!QImageDrag::canDecode(event))
	{
		qDebug("Cannot decode image, aborting.");
		event->ignore();
		return;
	}

	if ( QImageDrag::decode ( event, *image ) )
	{
		qDebug("Decoded image successfully, attempting to draw...");
		
		
		this->drawMaskedQImage ( QPoint ( event->pos().x(),
			event->pos().y()), *image ); // FIXME: use QPixmap

/*
	QCanvasText* i = new QCanvasText(this->canvas());
	i->setText("QCanvasText");
	i->move(50,50);
	i->show();
	this->canvas()->setBackgroundColor(Qt::white);
*/
	}
	else
	{
		qDebug("Failed to decode dropped image.");
	}



	return;
}


void Preview::drawMaskedQImage ( const QPoint& pos, const QImage& image )
{
	/* quite long winded, therefore in a separate method... */
	QPainter* painter = new QPainter(this);	// clipped

	/* create mask */ 
	QImage tmpMask = image.createHeuristicMask();
	QBitmap* mask = new QBitmap();
	mask->convertFromImage(tmpMask);
	
	QCanvasPixmap* pixmap = new QCanvasPixmap(image);
	pixmap->setMask(*mask);
	QCanvasPixmapArray* pixmapArray = new QCanvasPixmapArray();
	pixmapArray->setImage(0, pixmap);
	QCanvasSprite* sprite = new QCanvasSprite( pixmapArray, this->canvas() );
	
	sprite->setX(pos.x()); // FIXME: should make hotspot middle of dragimage
	sprite->setY(pos.y());
	sprite->draw(*painter);

	sprite->show();	
	
	this->canvas()->update();
	//this->update();
	
	painter->end();

	delete painter;
	
	return;
}

/*void Preview::contentsDropEvent ( QDropEvent *event )
{
	qDebug("contentsDropEvent(): Drop to %d:%d\n",
		event->pos().x(), event->pos().y() );

	return;
}*/


void Preview::dragEnterEvent ( QDragEnterEvent* event )
{
	event->accept( QImageDrag::canDecode(event) );
	//event->accept( true );
	
	return;
}


} // ns Editor

} // ns TV
