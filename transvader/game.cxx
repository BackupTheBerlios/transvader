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
	install_sound ( DIGI_AUTODETECT, MIDI_AUTODETECT, NULL );
	
	set_color_depth(16);
	
	dblbuffer = create_bitmap ( 800, 600 );
	
	clear_to_color ( screen, makecol16(0, 0, 0) );

	this->setSpeed(1);
	
	std::cout << "Game::Game(): finished.\n" << std::endl ;

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

/*
 * main game loop
 */
void Game::run()
{
	int c = 0;

	Player *player = new Player();

	while ( ( c >> 8 ) != KEY_ESC )
	{
		if ( keyboard_needs_poll() )
		{
			poll_keyboard();
		}

		if ( keypressed() )
			c = readkey();

		this->updateScreen();
	}

	return;
}

/*
 * update the double buffer using current object information
 * and blit it to the screen bitmap
 * TODO: implement simple "dirty" flag for whole screen to avoid
 * absolutely unnecessary blitting operations
 */
void Game::updateScreen()
{
	/* clear double buffer to color 0 */
	clear_bitmap ( this->dblbuffer );

	/* write debugging information to top of screen */
	textprintf( this->dblbuffer, font, 0, 0,
		makecol16(0, 150, 0),
		"Cycles left: %d", this->speedcounter);
		
	/* copy double buffer to screen */
	acquire_screen();
	blit ( this->dblbuffer, screen, 0, 0, 0, 0, 800, 600 );
	release_screen();

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

} // namespace TV
