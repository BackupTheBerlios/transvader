/******************************************************************************
 *  rectangle.cxx
 *
 *  Implements rectangles.
 *
 *  Author: Michael Prinzinger, Leslie Polzer, Mark Roesel
 *  Created: 2004-??-?? / Last updated: 2004-06-26
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/

#ifndef RECTANGLE_HXX
#define RECTANGLE_HXX

#include <iostream>

#include "point.hxx"


namespace TV
{

class Rectangle
{
	

	public:
		
		Rectangle ();
		Rectangle ( Point new_p, int new_w, int new_h );
		Rectangle ( Rectangle& );
		Rectangle ( Rectangle* );		
		
		~Rectangle();

        bool operator == ( const Rectangle& );
        Rectangle& operator = ( Rectangle& );
        Rectangle& operator + ( Rectangle& );
        Rectangle& operator += ( int );
        Rectangle& operator -= ( int );
	
		bool intersects ( Rectangle& );
		bool intersects ( Point& );
		
		int commonPixels ( Rectangle& );
		Rectangle& commonRectangle ( Rectangle& );

		Point getP() const;
		int getW() const;
		int getH() const;
		
		void setP(Point new_p);
		void setW(int new_w);
		void setH(int new_h);
		
		void setCoordinates (Point new_p, int new_w, int new_h);

		friend std::ostream& operator << ( std::ostream&, const Rectangle& );
		
		private:
			
			Point p;	
			int w, h;
	
};



} // namespace TV

#endif
