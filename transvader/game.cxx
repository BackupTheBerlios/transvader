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
#include "pageflipper.hxx"
#include "game.hxx"


namespace TV
{

/* hackish, subject to change */
const unsigned short res_x = 800;
const unsigned short res_y = 600;
const unsigned short depth =   32;
const unsigned short gameSpeed =   50;

/*
 * initialize drivers and some things more
*/
Game::Game()
	:
	speedcounter(0)
{
	/* initialize Allegro */
	if ( install_allegro ( SYSTEM_AUTODETECT, &errno, atexit ) )
	{
		throw Exception ( std::string("Could not initialize Allegro (")
			+ strerror(errno) + std::string(")"), ERR_FATAL );
	}

	/* init graphics mode */
	set_color_depth(depth);
	set_color_conversion ( COLORCONV_TOTAL | COLORCONV_DITHER | COLORCONV_KEEP_TRANS );
	
	//#ifdef ALLEGRO_VRAM_IS_SINGLE_SURFACE
		int ret = set_gfx_mode ( GFX_AUTODETECT_WINDOWED,
			res_x, res_y, res_x*2, res_y );
	/*#else
		int ret = set_gfx_mode ( GFX_AUTODETECT_WINDOWED,
			800, 600, 0, 0 );
	#endif*/
	
	if ( ret < 0 )
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

        LOCK_VARIABLE(this->fps);
        LOCK_FUNCTION(Game::fps_timer);
	install_param_int_ex( Game::fps_timer, static_cast<void*>(this),
		              SECS_TO_TIMER(1) );

	install_sound ( DIGI_AUTODETECT, MIDI_AUTODETECT, NULL );
	clear_to_color ( screen, makecol(0, 0, 0) );

	this->setSpeed(gameSpeed);

	this->display = new Pageflipper ( SCREEN_W, SCREEN_H );
	
	return;

}

Game::~Game()
{
	//delete ( this->display );

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
 * sets the fps counter variable = 0.
 * called every 1 second by install_param_int_ex above.
 * it also calculates the average fps value
 */

void Game::fps_timer(void *inst)
{
        Game* there = (static_cast<Game*>(inst));

        there->last_fps = there->fps;
        there->fps=0;
        there->avg_fps=(there->avg_fps + there->last_fps )/2;

        return;
}
END_OF_STATIC_FUNCTION(fps_timer);



/*
 * main game loop
 */
void Game::run()
{
	int c = 0;
	/*int pagenum = 0;
	BITMAP *page[2];

	page[0] = create_video_bitmap ( SCREEN_W, SCREEN_H );
	page[1] = create_video_bitmap ( SCREEN_W, SCREEN_H );*/

	this->player = new Player();

	while ( !key[KEY_ESC] )
	{
		if ( keyboard_needs_poll() )
		{
			poll_keyboard();
		}

		while ( this->speedcounter > 0 )
		{
                        this->updateData();
			speedcounter--;
		}

		clear_bitmap ( this->display->getBitmap() );
		
		textprintf ( this->display->getBitmap(), font, 0, 10,
			makecol(0, 235, 0),
			"Cycles left: %d | Angle: %d | Player: (%d,%d)",
			this->speedcounter, fixtoi(this->player->angle),
			fixtoi(this->player->x), fixtoi(this->player->y)
				);

		/* write current and average fps on top of screen */
        	textprintf ( this->display->getBitmap(), font, 0, 0, makecol(0,200,0),
			"FPS: %d  Average FPS: %d",
			this->last_fps, this->avg_fps);

		this->player->draw ( this->display->getBitmap() );
		
		this->display->draw();
		
		this->fps++;
	}

	delete ( this->player );

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

/* OBSOLETE
 * draw. target algorithm: "dirty rectangles"
 */
void Game::updateScreen()
{
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
