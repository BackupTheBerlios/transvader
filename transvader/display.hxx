#ifndef DISPLAY_HXX
#define DISPLAY_HXX


#include "rectangle.hxx"
#include "sprite.hxx"

namespace TV
{

class Display
{
	protected:
		BITMAP *dblbuffer;
		list <Sprite> sprites;
		list <Sprite> old_sprites;

		void invalidateRect( const Rectangle& r );

	public:
		Display();
		~Display();
	
		void addSprite ( const Sprite& sprite );
		
		void prepare();
		void draw();
};

} // namespace TV

#endif
