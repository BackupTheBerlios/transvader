// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#include <string>
#include <iostream>

#include <stdlib.h>
#include <stdio.h>

#include <allegro.h>

#include "exception.hxx"
#include "player.hxx"

#include "game.hxx"


namespace TV
{

/*
 * initialize drivers and some things more
*/
Game::Game()
{
	/* initialize Allegro */
	if ( install_allegro ( SYSTEM_AUTODETECT, &errno, atexit ) )
	{
		throw Exception ( std::string("Could not initialize Allegro (")
			+ strerror(errno) + std::string(")"), ERR_FATAL );
	}
	
	/* init graphics mode */
	set_color_depth(16);
	set_color_conversion ( COLORCONV_TOTAL | COLORCONV_DITHER | COLORCONV_KEEP_TRANS );
	
	if ( set_gfx_mode ( GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0 ) < 0 )
	{
		throw Exception ( std::string("Could not set graphics mode (")
			+ allegro_error + std::string(")"), ERR_FATAL );
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

	this->fps = 0;
        this->avg_fps = 1;
        this->last_fps = 0;

	remove_param_int ( Game::fps_timer, static_cast<void*>(this) );
        LOCK_VARIABLE(this->fps);
        LOCK_FUNCTION(Game::fps_timer);
	install_param_int_ex( Game::fps_timer, static_cast<void*>(this),
		              SECS_TO_TIMER(1) );

	install_sound ( DIGI_AUTODETECT, MIDI_AUTODETECT, NULL );
	clear_to_color ( screen, makecol(0, 0, 0) );

	this->setSpeed(80);
	
	return;

}

Game::~Game()
{
	allegro_exit();
	
	return;
}

/*
 * increment the game speed counter.
 * called at regular intervals ( changeable via setSpeed() )
 * via interrupt
 */
void Game::incSpeedCounter ( void *inst )
{
	(static_cast<Game*>(inst))->speedcounter++;

	return;
}
END_OF_FUNCTION(incSpeedCounter)

void Game::fps_timer(void *inst)
{
        (static_cast<Game*>(inst))->last_fps = (static_cast<Game*>(inst))->fps;
        (static_cast<Game*>(inst))->fps=0;
        (static_cast<Game*>(inst))->avg_fps=((static_cast<Game*>(inst))->avg_fps + (static_cast<Game*>(inst))->last_fps )/2;

        return;
}
END_OF_STATIC_FUNCTION(fps_timer);



/*
 * main game loop
 */
void Game::run()
{
	int c = 0;

	this->player = new Player();

	while ( ( c >> 8 ) != KEY_ESC )
	{
		if ( keyboard_needs_poll() )
		{
			poll_keyboard();
		}

		if ( keypressed() )
			c = readkey();

		while ( this->speedcounter > 0 )
		{
			this->updateData();
			speedcounter--;
		}

		this->updateScreen();
		this->fps++;
	}

	return;
}

/*
 * update game data
 */
void Game::updateData()
{
	this->player->update();

	return;
}

/*
 * draw. target algorithm: "dirty rectangles"
 */
void Game::updateScreen()
{
	vsync();
	acquire_bitmap ( screen );
	//clear_bitmap ( screen );
	
	/* write debugging information to top of screen */

	textprintf ( screen, font, 0, 10,
		makecol(0, 235, 0),
		"Cycles left: %d | Angle: %d",
		this->speedcounter, fixtoi(this->player->angle) );

	
	/*write current and avreage fps on top of screen*/
        textprintf(screen,font,0,0,makecol(0,200,0),"FPS: %d  Average FPS: %d", this->last_fps, this->avg_fps);

	/* draw player sprite */
	this->player->draw ( screen );

	release_bitmap ( screen );
	
	return;
}

inline void Game::setSpeed ( unsigned short speed )
{
	remove_param_int ( Game::incSpeedCounter, static_cast<void*>(this) );

	LOCK_FUNCTION(Game::incSpeedCounter)
	LOCK_VARIABLE(this->speedcounter)

	install_param_int_ex( Game::incSpeedCounter, static_cast<void*>(this),
		BPS_TO_TIMER(speed) ); //FIXME: error checking

	return;
}

//FPS Timer





} // namespace TV
