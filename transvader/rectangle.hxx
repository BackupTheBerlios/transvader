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
		friend std::ostream& operator << ( std::ostream& , const Rectangle& );
		
		bool doesTraverse ( Rectangle& );
		bool doesTraverse ( Point& );
		
		int commonPixels ( Rectangle& );
		Rectangle& Rectangle::unite ( Rectangle& );

		unsigned short getX();
		unsigned short getY();
		unsigned short getW();
		unsigned short getH();
		
		void setX(unsigned short new_x);
		void setY(unsigned short new_y);
		void setW(unsigned short new_w);
		void setH(unsigned short new_h);
		
};

} // namespace TV

#endif
