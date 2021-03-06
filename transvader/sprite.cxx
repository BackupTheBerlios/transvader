// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#include <string>
#include <iostream>

#include "exception.hxx"

#include "rectangle.hxx"
#include "sprite.hxx"


namespace TV
{


Sprite::Sprite ( std::string location )
	:
	description("A generic sprite"),
	type("Generic"),
	angle(0)
{
	std::cout << "Attempt to create new sprite from \""
		<< location << + "\"... " ;
	
	if ( ( this->default_image = load_bitmap ( location.c_str(), NULL ) )
		== NULL )
	{
		throw Exception ( "Could not open sprite file " + location, ERR_FATAL );
	}
	
	this->width = this->default_image->w;
	this->height = this->default_image->h;
	
	std::cout << "succeeded, dimensions " << this->width
		<< "x" << this->height << "x"
		<< bitmap_color_depth ( this->default_image )
		<< std::endl ;
	
	/* pageflipper only, fixme */
	#ifdef ALLEGRO_WINDOWS
	BITMAP *tmp = create_video_bitmap ( this->width, this->height );
	if ( tmp != NULL )
	{
		destroy_bitmap(this->default_image);
		this->default_image = tmp;
	}
	#endif
	
	return;
}


Sprite::~Sprite()
{
	//call this->onDestroy(this);
}

std::string& Sprite::getDescription()
{
	return ( this->description );
}

std::string& Sprite::getType()
{
	return ( this->type );
}


/* draw fallback */
void Sprite::draw ( BITMAP* bitmap )
{
		/* FIXME */
}

} /* namespace TV */
