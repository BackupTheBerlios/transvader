#include "maingui.hxx"

namespace TV
{

namespace Editor
{


MainGUI::MainGUI ( QWidget * parent, const char * name )
	: QMainWindow ( parent, name )
{
	this->setCaption( "Transvader Mission Editor v0.1" );
	this->statusBar()->message( "Ready", 2000 );
	this->resize( 800, 600 );

	QSplitter* splitter = new QSplitter(this);
	this->setCentralWidget( splitter );

	Preview* preview = new Preview(splitter);
	preview->setFocus();
	
	Palette* palette = new Palette(splitter);

	
	this->show();

	return;
}

MainGUI::~MainGUI()
{
	return;
}


} // ns Editor

} // ns TV
