#include "palette.hxx"

namespace TV
{

namespace Editor
{


Palette::Palette ( QWidget * parent, const char * name )
	: QIconView( parent, name )
{
	this->setItemsMovable(false);
	this->setAutoArrange(true);

	new QIconViewItem ( this, "Player", QPixmap("./level1.png") );
	new QIconViewItem ( this, "Player", QPixmap("./level1.png") );
	new QIconViewItem ( this, "Player", QPixmap("./level1.png") );
	new QIconViewItem ( this, "Player", QPixmap("./level1.png") );		

	return;
}


Palette::~Palette()
{
	return;
}


QDragObject* Palette::dragObject()
{
	qDebug("Starting drag of '%s'", currentItem()->text().ascii() );

	return ( new QImageDrag ( currentItem()->pixmap()->convertToImage(), this,
		currentItem()->text().ascii() ) );
}


} // ns Editor

} // ns TV
