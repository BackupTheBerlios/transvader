/******************************************************************************
 *  point.hxx
 *
 *  Implements two-dimensional points.
 *
 *  Author: Mark Roesel, Leslie Polzer, 
 *  Created: 2004-06-26 / Last updated: 2004-06-26
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/
#ifndef POINT_HXX
#define POINT_HXX

#include <ostream>

namespace TV
{

class Point
{	
	public:
		Point(int new_x = 0, int new_y = 0);
	
		~Point();

		Point& operator =  ( const Point& p );
		Point& operator +  ( const Point& p ) const;
		Point& operator += ( Point& p );
		Point& operator -  ( const Point& p ) const;
		Point& operator -= ( Point& p );
		bool   operator == ( const Point& p ) const;
	
		int distanceTo ( Point& p ) const;
	
		friend std::ostream& operator << ( std::ostream& out, const Point& p );
	
		int x;
		int y;
};

}

#endif
