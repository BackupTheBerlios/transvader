#include "palette.hxx"

namespace TV
{

namespace Editor
{


Palette::Palette ( QWidget * parent, const char * name )
	: QIconView( parent, name )
{
	const char* TESTIMG = "../data/player/level1.png";
	
	this->setItemsMovable(false);
	this->setAutoArrange(true);

	Editor::IconViewItem* icon;
	
	icon = new Editor::IconViewItem ( this );
	icon->setText ( "Player1", true, true );
	icon->setPixmap(QPixmap(TESTIMG));
	
	return;
}


Palette::~Palette()
{
	return;
}




QDragObject* Palette::dragObject()
{
	qDebug("Starting drag of '%s'", currentItem()->text().ascii() );

	TV::Editor::DragObject* drag = new TV::Editor::DragObject ( this );
	
	drag->setPixmap ( *currentItem()->pixmap(),
		QPoint( currentItem()->pixmapRect().width() / 2,
		currentItem()->pixmapRect().height() / 2 ) );
	
	//return ( new QImageDrag ( currentItem()->pixmap()->convertToImage(), this,
	//	currentItem()->text().ascii() ) );
	
	return ( drag );
}


} // ns Editor

} // ns TV
