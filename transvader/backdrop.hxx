// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef BACKDROP_HXX
#define BACKDROP_HXX

#include <string>

#include <allegro.h>


namespace TV
{

class Backdrop : public Sprite
{
	public:

		Backdrop ( std::string filename );
		virtual ~Backdrop();
	
		virtual void update ();
		virtual void draw ( BITMAP* bitmap );
};

} /* namespace TV */

#endif
