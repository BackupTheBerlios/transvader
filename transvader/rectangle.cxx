// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Michael Prinzinger
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution


#include "rectangle.hxx"


namespace TV
{


Rectangle::Rectangle()
	: x(0), y(0), w(0), h(0)
{
}


Rectangle::~Rectangle()
{
}

Rectangle::Rectangle ( unsigned short new_x, unsigned short new_y,
			unsigned short new_w,unsigned short new_h )
	: x(new_x), y(new_y), w(new_w), h(new_h)
{
}

Rectangle::Rectangle (Rectangle& rect)
	: x(rect.x), y(rect.y), w(rect.w), h(rect.h)
{
}

/* compares two rectangles and returs if they are equal or not */

bool Rectangle::operator== ( Rectangle& rect )
{
	return ( this->x == rect.x && this->y == rect.y
		&& this->w == rect.w && this->h == rect.h );
}

/* assigns the values of one rectangle to another */

Rectangle& Rectangle::operator= ( Rectangle& rect )
{
	this->x = rect.x;
	this->y = rect.y;
	this->w = rect.w;
	this->h = rect.h;

	return ( *this );
}

/* get coordinates of the rectangle */

unsigned short Rectangle::getX()
{
	return ( this->x );
}

unsigned short Rectangle::getY()
{
	return ( this->y );
}

unsigned short Rectangle::getW()
{
	return ( this->w );
}

unsigned short Rectangle::getH()
{
	return ( this->h );
}


/* set coordinates of the rectangle */

void Rectangle::setX ( unsigned short new_x )
{
	this->x = new_x;
}

void Rectangle::setY ( unsigned short new_y )
{
	this->y = new_y;
}

void Rectangle::setW ( unsigned short new_w )
{
	this->w = new_w;
}

void Rectangle::setH ( unsigned short new_h )
{
	this->h = new_h;
}

bool Rectangle::doesTraverse ( Point& point )
{
	return ( false ); // edit me
}

} /* namespace TV */
