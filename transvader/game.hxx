// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef TV_HXX
#define TV_HXX

#include "player.hxx"

namespace TV
{

class Game
{
	private:
		volatile unsigned short speedcounter;


		static void incSpeedCounter ( void *inst );
		static void fps_timer(void *inst);
		int install_param_int(void (*proc)(void *), void *param, int speed);

		volatile int fps;
                volatile int avg_fps;
                volatile int last_fps;


		Player *player;

		unsigned short speed;

		void updateData();
		void updateScreen();

	public:
		Game();
		~Game();
                
		inline void setSpeed ( unsigned short speed );

		
		void run();

};

} // namespace TV

#endif
