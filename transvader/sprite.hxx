// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef SPRITE_HXX
#define SPRITE_HXX

#include <string>

#include <allegro.h>


namespace TV
{

class Sprite /* base class */
{
	protected:
		BITMAP *default_image;
	
		fixed x, y;
		unsigned short width, height;
	
	public:
		fixed angle;	
	
		Sprite ( std::string filename );
		virtual ~Sprite();
	
		virtual void update () = 0;
		virtual void draw ( BITMAP* bitmap );
};

} /* namespace TV */

#endif
