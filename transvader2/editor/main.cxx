#include <qapplication.h>

#include "maingui.hxx"


using TV::Editor::MainGUI;


int main ( int argc, char** argv )
{
	QApplication editor ( argc, argv );
	MainGUI maingui;
    
	editor.setMainWidget( &maingui );
	maingui.show();
    
	return ( editor.exec() );
}
