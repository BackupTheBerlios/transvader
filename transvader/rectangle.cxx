// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#include <string>
#include <iostream>

#include "exception.hxx"

#include "rectangle.hxx"


namespace TV
{


Rectangle::Rectangle()
:
x(0),
y(0),
w(0),
h(0)
{}

Rectangle::Rectangle (unsigned short new_x,unsigned short new_y,unsigned short new_w,unsigned short new_h)
:
x(new_x),
y(new_y),
w(new_w),
h(new_h)
{}

Rectangle::Rectangle (Rectangle& rect)
:
x(rect.x),
y(rect.y),
w(rect.w),
h(rect.h)
{}

unsigned short Rectangle::getX()
{
return(this->x);
}

unsigned short Rectangle::getY()
{
return(this->y);
}

unsigned short Rectangle::getW()
{
return(this->w);
}

unsigned short Rectangle::getH()
{
return(this->h);
}

Rectangle::~Rectangle()
{}

} /* namespace TV */
