#include "palette.hxx"

namespace TV
{

Palette::Palette()
{
	MkDialogue(ADAPTIVE, "Object Palette", W_FLOATING);
	MkCanvas ( 0, 0, 100, 200, NULL, static_cast<void*>(this) );
	//AddTextBox(RIGHT, "A simple window showing some buttons. Press the button to the left and you will get a new identical window.", 200, 0, 0);
	DisplayWin();	
}
	
Palette::~Palette()
{
	//...
}

}
