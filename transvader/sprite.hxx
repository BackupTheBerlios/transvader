// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer, Michael Prinzinger
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef SPRITE_HXX
#define SPRITE_HXX

#include <string>

#include <allegro.h>

#include "rectangle.hxx"


namespace TV
{

class Sprite /* base class */
{
	protected:
		std::string description;
		std::string type;


		unsigned int width, height;
	
		BITMAP *default_image;

	public:
		/* FIXME: should be protected */
		unsigned int x, y;	
		fixed angle;	
	
		Sprite ( std::string );
		virtual ~Sprite();
	
		virtual void update () = 0;
		virtual void draw ( BITMAP* );
		virtual std::string& getDescription();
		virtual std::string& getType();
};

} /* namespace TV */

#endif
