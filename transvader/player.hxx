// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef PLAYER_HXX
#define PLAYER_HXX

#include "sprite.hxx"


namespace TV
{

class Player : public Sprite
{
	private:
	
	public:
		Player ( std::string location );
		virtual ~Player();
	
/*not yet*/	//virtual void draw ( BITMAP* bitmap ) const;
}

} // namespace TV

#endif
