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
		void setX(unsigned short new_x);
		void setY(unsigned short new_y);
		void setW(unsigned short new_w);
		void setH(unsigned short new_h);
		
};

} // namespace TV

#endif
