#ifndef DISPLAY_HXX
#define DISPLAY_HXX


#include <list>

#include "rectangle.hxx"
#include "sprite.hxx"

namespace TV
{

class Display
{
	protected:
		//BITMAP *dblbuffer;
		std::list <Sprite*> sprites;
		std::list <Rectangle*> old_sprites;

		void invalidateRect( const Rectangle& r );
		void findRectangles();

	public:
		Display();
		~Display();
	
		void addSprite ( Sprite* sprite );
		
		void prepare();
		void optimize();
		void draw();
};

} // namespace TV

#endif
