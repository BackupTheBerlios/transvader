// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Michael Prinzinger
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#include <allegro.h>

#include "exception.hxx"
#include "doublebuffer.hxx"


namespace TV
{

Doublebuffer::Doublebuffer ( int width, int height )
{

        buffer = create_bitmap ( width, height );
	if ( buffer == NULL )
	{
		throw Exception ( std::string("Unable to create buffer i(FIXME).\n")
   			+ std::string(")"), ERR_FATAL );
       	}
        clear(buffer);	//FIXME: really necessary?
	return;
}


Doublebuffer::~Doublebuffer()
{
	        destroy_bitmap ( buffer );
}


void Doublebuffer::draw()
{

     blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
     // show_system_bitmap (buffer);

     return;
}


BITMAP *Doublebuffer::getBitmap()
{
	return ( this->buffer );
}

} /* namespace TV */



