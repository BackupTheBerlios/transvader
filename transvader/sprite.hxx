// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef SPRITE_HXX
#define SPRITE_HXX

namespace TV
{

class Sprite
{
	private:
		unsigned short x, y;
		unsigned short size_x, size_y;
	
	public:
		Sprite();
		virtual ~Sprite();
	
		virtual void draw() const = 0;
}

} // namespace TV

#endif
