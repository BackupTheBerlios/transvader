#ifndef DISPLAY_HXX
#define DISPLAY_HXX



namespace TV
{

class Rectangle
{
	protected:
		unsigned short x, y, w, h;

	public:
		Rectangle();
		Rectangle ( unsigned short x, unsigned short y, unsigned short w, unsigned short h );
		Rectangle ( Rectangle& rect );
		~Rectangle();
	
		bool doesTraverse ( Rectangle& rect );
		int commonPixels ( Rectangle& rect );
		Rectangle& unite ( Rectangle& rect );
};

} // namespace TV

#endif
