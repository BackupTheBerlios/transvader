#ifndef EDITOR_MAINGUI_HXX
#define EDITOR_MAINGUI_HXX

#include <qmainwindow.h>
#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qstatusbar.h>
#include <qsplitter.h>

#include "preview.hxx"
#include "palette.hxx"


namespace TV
{

namespace Editor
{


class MainGUI : public QMainWindow
{
	Q_OBJECT
	
	public:
		MainGUI ( QWidget * parent = 0, const char * name = "MainGUI" );
		~MainGUI();
	
	private:
};


} // ns Editor

} // ns TV

#endif
