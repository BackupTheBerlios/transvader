// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#include <string>

#include "exception.hxx"

#include "sprite.hxx"
#include "backdrop.hxx"

namespace TV
{


Backdrop::Backdrop ( std::string location)
	:
	Sprite ( location )
{
	return;
}


Backdrop::~Backdrop()
{
}

void Backdrop::draw ( BITMAP* )
{
}

void Backdrop::update ( )
{
}


} /* namespace TV */
