#include "editor.hxx"
#include "cgui.h"

namespace TV
{

Editor::Editor()
{
	int ret = InitCgui ( 800, 600, 32 );

	return;
}

Editor::~Editor()
{
	return;
}

void Editor::run()
{
	ProcessEvents();

	return;
}

} /* namespace TV */
