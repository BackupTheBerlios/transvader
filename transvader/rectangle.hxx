#ifndef RECTANGLE_HXX
#define RECTANGLE_HXX



namespace TV
{

class Rectangle
{
	protected:
		unsigned short x, y, w, h;

	public:
		Rectangle();
		Rectangle (unsigned short x,unsigned short y,unsigned short w,unsigned short h );
		Rectangle ( Rectangle& rect );
		~Rectangle();
	
		bool doesTraverse ( Rectangle& rect );
		int commonPixels ( Rectangle& rect );
		Rectangle& unite ( Rectangle& rect );
		
		unsigned short getX();
		unsigned short getY();
		unsigned short getW();
		unsigned short getH();
};

} // namespace TV

#endif
