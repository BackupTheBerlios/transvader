#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <allegro.h>

#include "exception.hxx"
#include "tv.hxx"


TV::TV()
{
	if ( install_allegro ( SYSTEM_AUTODETECT, &errno, atexit ) )
	{
		char* errmsg = new char[200];
		
		sprintf(errmsg, "Could not initialize Allegro (%s)",
			strerror(errno) );
		throw Exception(errmsg, ERR_FATAL);
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
