#include <stdlib.h>
#include <allegro.h>

#include "exception.hxx"
#include "tv.hxx"


TV::TV()
{
	if ( !allegro_init() )
	{
		throw Exception("Could not initialize Allegro", ERR_FATAL);
	}
	
	set_window_title("Transvader-DEVEL");
	
	return;	
}

TV::~TV()
{
	allegro_exit();
	
	return;
}

void TV::run()
{
	return;
}
