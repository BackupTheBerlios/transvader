// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer, Michael Prinzinger
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef RECTANGLE_HXX
#define RECTANGLE_HXX


#include <iostream>

#include "types.hxx"


namespace TV
{

class Rectangle
{
	

	public:
		unsigned short x, y, w, h;
		
		Rectangle ();
		Rectangle ( unsigned short, unsigned short,
				unsigned short, unsigned short );
		Rectangle ( Rectangle& );
		Rectangle ( Rectangle* );		
		
		~Rectangle();

        bool operator == ( const Rectangle& );
        Rectangle& operator = ( Rectangle& );
        Rectangle& operator + ( Rectangle& );
        Rectangle& operator += ( int );
        Rectangle& operator -= ( int );
		std::ostream& operator << ( std::ostream& );
		
		bool doesTraverse ( Rectangle& );
		bool doesTraverse ( Point& );
		
		int commonPixels ( Rectangle& );
		Rectangle& commonRectangle ( Rectangle& );

		unsigned short getX();
		unsigned short getY();
		unsigned short getW();
		unsigned short getH();
		
		void setCoordinates (unsigned short, unsigned short, unsigned short, unsigned short);
		
};

} // namespace TV

#endif
