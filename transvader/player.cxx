// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#include <string>
#include <iostream>

#include "player.hxx"


namespace TV
{

Player::Player ( std::string location )
	:
	Sprite ( location )
{
	return;
}


Player::~Player()
{
	return;
}


void Player::draw ( BITMAP* bitmap ) const
{
	static int i = 0;

	rotate_sprite ( bitmap, this->default_image, 400, 300, (i += 5) << 16 );
	//draw_sprite ( bitmap, this->default_image, 400, 300 );

	return;
}

} /* namespace TV */
