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
	// Main window
	MkDialogue(FILLSCREEN, "Transvader Level Editor", 0);
	int result =  AddButton(TOPLEFT, "Exit Editor", quit, NULL);	
	DisplayWin();
	
	// Level preview
	MkDialogue(ADAPTIVE, "Level Preview", W_FLOATING);
	MkCanvas ( 0, 0, 400, 300, mouse_cb, static_cast<void*>(this) );
	DisplayWin();
	
	// Object palette
	MkDialogue(ADAPTIVE, "Object Palette", W_FLOATING);
	MkCanvas ( 0, 0, 100, 200, mouse_cb, static_cast<void*>(this) );
	//AddTextBox(RIGHT, "A simple window showing some buttons. Press the button to the left and you will get a new identical window.", 200, 0, 0);
	DisplayWin();
	
	// Object properties
	MkDialogue(ADAPTIVE, "Property Editor", W_FLOATING);
	AddTextBox(RIGHT, "A simple window showing some buttons. Press the button to the left and you will get a new identical window.", 200, 0, 0);
	DisplayWin();	
	
	ProcessEvents();

	return;
}


void Editor::mouse_cb ( BITMAP* bmp, int mx, int my, void* data )
{
	static short mx_old = -2, my_old = -2, mb_old = -2;
	
	/* react only if needed */
	if ( mx != -1				/* this is not a refresh call */
		&& mx_old == mx			/* X coordinate hasn't changed */
		&& my_old == my			/* Y coordinate hasn't changed */
		&& mb_old == mouse_b	/* button state hasn't changed */
		)
	{
			return;
	}
	
	mx_old = mx;
	my_old = my;
	mb_old = mouse_b;
	
	static unsigned int callnum = 0;
	
	TV::Editor* editor = static_cast<TV::Editor*>(data);
	
	std::cout << "mouse_cb() " << callnum++ << ": " << mx << " " << my << std::endl ;
	
	return;
}


void Editor::quit(void *data)
{
	(void)data;
	StopProcessEvents();
}


void Editor::closeWin (void *data)
{
	(void)data;	
	CloseWin(NULL);
}


} /* namespace TV */
