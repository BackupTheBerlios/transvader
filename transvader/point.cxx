/******************************************************************************
 *  point.cxx
 *
 *  Implements two-dimensional points.
 *
 *  Author: Mark Roesel, Leslie Polzer
 *  Created: 2004-06-26 / Last updated: 2004-06-26
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/

#include <math.h>

#include "point.hxx"


namespace TV
{

Point::Point(int new_x, int new_y)
	:
	x(new_x),
	y(new_y)
{
	return;
}
	
Point::~Point()
{
	return;	
}

Point& Point::operator =  ( const Point& p )
{
	this->x = p.x;
	this->y = p.y;
	
	return *this;
}

Point& Point::operator +  ( const Point& p ) const
{
	return *(new Point( this->x + p.x, this->y + p.y ));
}

Point& Point::operator += ( Point& p )
{
	this->x += p.x;
	this->y += p.y;
	
	return *this;
}

Point& Point::operator -  ( const Point& p ) const
{
	return *(new Point( this->x - p.x, this->y - p.y ));
}

Point& Point::operator -= ( Point& p )
{
	this->x -= p.x;
	this->y -= p.y;
	
	return *this;
}

bool Point::operator == ( const Point& p ) const
{
	return (this->x == p.x && this->y == p.y);
}

int Point::distanceTo(Point& p) const
{
	int x_dist = abs( this->x - p.x );
	int y_dist = abs( this->y - p.y );
	
	return ( (int)round(sqrt(x_dist^2 + y_dist^2)) );
}

std::ostream& operator << ( std::ostream& out, const Point& p )
{
	out << "(" << p.x << "," << p.y << ")";

	return out;
}

} // namespace TV
