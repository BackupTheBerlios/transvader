#include "editor.hxx"
#include <cgui.h>
#include "palette.hxx"


namespace TV
{

Editor::Editor()
{
	int ret = InitCgui ( 1024, 768, 32 );

	return;
}


Editor::~Editor()
{
	return;
}


void Editor::run()
{
	int result;
	
	// Main window
	MkDialogue(FILLSCREEN, "Transvader Level Editor", 0);
	
	// Menu bar
	result = MakeMenuBar();
	result = MkMenuBarItem("File", NULL, NULL);
	result = MkMenuBarItem("Edit", NULL, NULL);
	EndMenuBar();
	
	
	//result =  AddButton(RIGHT, "Menu 1", quit, NULL);
	//result =  AddButton(RIGHT, "Menu 2", quit, NULL);
	//result =  AddButton(RIGHT, "Menu 3", quit, NULL);
	result =  AddButton(RIGHT, "Exit Editor", quit, NULL);
	
	// Windows
	MkCanvas (DOWNLEFT, 800, 692, mouse_cb, static_cast<void*>(this) );
	MkCanvas (RIGHT, 213, 345, mouse_cb, static_cast<void*>(this) );
	MkCanvas (DOWN, 213, 345, mouse_cb, static_cast<void*>(this) );
	
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




/* TEMP_CODE
// Level preview
//MkDialogue(DOWNLEFT, "Level Preview", W_FLOATING);
//MkCanvas ( 0, 30, 800, 768, mouse_cb, static_cast<void*>(this) );
//DisplayWin();

// Object palette
//Palette pal;

//MkDialogue(ADAPTIVE, "Object Palette", W_FLOATING);
//MkCanvas ( 0, 0, 100, 200, mouse_cb, static_cast<void*>(this) );
//AddTextBox(RIGHT, "A simple window showing some buttons. Press the button to the left and you will get a new identical window.", 200, 0, 0);
//DisplayWin();

// Object properties
//MkDialogue(ADAPTIVE, "Property Editor", W_FLOATING);
//AddTextBox(RIGHT, "A simple window showing some buttons. Press the button to the left and you will get a new identical window.", 200, 0, 0);
//DisplayWin();	
*/
