#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <allegro.h>

#include "exception.hxx"
#include "tv.hxx"


TV::TV()
{
	/* initialize Allegro */
	if ( install_allegro ( SYSTEM_AUTODETECT, &errno, atexit ) )
	{
		char* errmsg = new char[200];
		
		sprintf(errmsg, "Could not initialize Allegro (%s)",
			strerror(errno) );
		throw Exception(errmsg, ERR_FATAL);
	}
	
	/* init graphics mode */
	if ( set_gfx_mode ( GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0 ) < 0 )
	{
		char* errmsg = new char[200];
		
		sprintf(errmsg, "Could not set graphics mode (%s)",
			allegro_error );
			
		throw Exception(errmsg, ERR_FATAL);
	}

	/* set configuration variables */
	set_window_title("Transvader-DEVEL");
	set_display_switch_mode ( SWITCH_PAUSE );
	if ( !enable_triple_buffer() )
	{
		allegro_message ( "Triple buffering enabled\n" );
	}
	
	/* init keyboard, timer and sound */
	install_keyboard();
	install_timer();
	install_sound ( DIGI_AUTODETECT, MIDI_AUTODETECT, NULL );
	
	set_color_depth(16);
	
	clear_to_color ( screen, makecol16(0, 0, 0) );
	
	allegro_message ( "TV::TV(): finished.\n" );

	readkey();
	
	return;
}

TV::~TV()
{
	allegro_exit();
	
	return;
}

void TV::run() const
{
	

	return;
}
