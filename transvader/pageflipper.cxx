// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer, Michael Prinzinger
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#include <allegro.h>

#include "exception.hxx"
#include "pageflipper.hxx"


namespace TV
{

Pageflipper::Pageflipper ( int width, int height )
	:
	pagenum(0)
{
	for ( int i = 0; i < 2; i++ )
	{
		page[i] = create_video_bitmap ( width, height );
		if ( page[i] == NULL )
		{
			throw Exception ( std::string("Unable to create buffer i(FIXME).\n")
	   			+ std::string(")"), ERR_FATAL );
        	}
	        clear(page[i]);	//FIXME: really necessary?
	}
	
	return;
}


Pageflipper::~Pageflipper()
{
	for ( int i = 0; i < 2; i++ )
	        destroy_bitmap ( page[i] );
}


void Pageflipper::draw()
{
     show_video_bitmap ( page[pagenum] );

     this->pagenum = abs ( this->pagenum - 1 );

     clear ( page[pagenum] );	//FIXME: should be in Game::run() rather

     return;
}


BITMAP *Pageflipper::getBitmap()
{
	return ( this->page[pagenum] );
}

} /* namespace TV */



