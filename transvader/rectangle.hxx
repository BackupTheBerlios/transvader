#ifndef RECTANGLE_HXX
#define RECTANGLE_HXX


#include "types.hxx"


namespace TV
{

class Rectangle
{
	

	public:
		unsigned short x, y, w, h;
		
		Rectangle ();
		Rectangle ( unsigned short x, unsigned short y,
				unsigned short w, unsigned short h );
		Rectangle ( Rectangle& rect );
		Rectangle ( Rectangle* rect );		
		
		~Rectangle();

                bool Rectangle::operator==(Rectangle& rect);
                Rectangle& Rectangle::operator=(Rectangle& rect);
		
		bool doesTraverse ( Rectangle& rect );
		bool doesTraverse ( Point& point );
		
		int commonPixels ( Rectangle& rect );
		Rectangle& Rectangle::unite(Rectangle& rect);

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
