// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer, Michael Prinzinger
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef TV_HXX
#define TV_HXX

#include "application.hxx"
#include "display.hxx"
#include "player.hxx"

namespace TV
{

class Game : public Application
{
	private:
		volatile unsigned short speedcounter;


		static void incSpeedCounter ( void *);
		static void fps_timer(void *);
		int install_param_int(void (*proc)(void *), void *, int);

		volatile int fps;
                volatile int avg_fps;
                volatile int last_fps;


		Player *player;

		unsigned short speed;

		void updateData();
		void updateScreen();
		
		Display* display;

	public:
		Game();
		~Game();
                
		inline void setSpeed ( unsigned short );

		
		void run();

};

} // namespace TV

#endif
