
#include <list>
#include <iostream>

#include "sprite.hxx"
#include "display.hxx"

namespace TV
{

Display::Display()
{
	return;
}


Display::~Display()
{
	return;
}


void Display::addSprite ( Sprite *sprite )
{
	std::cout << "Display::addSprite(): adding sprite \""
		<< sprite->getDescString() << "\"..." << std::endl ;

	this->sprites.push_back ( sprite );
	
	return;
}

/**
 * optimize our list of dirty rectangles:
 * 	- unite overlapping rectangles (maybe; only if not too many new objects have to be added)
 *	- sort rectangles by their coordinates: higher rects go first 
 */
void Display::optimize()
{
	return;
}


void Display::draw()
{
	/**
	   * fixme: this all should go into prepare(), which will draw to the double buffer.
	   *	    this routine will then just copy dirty rectangles from the double buffer.
	   */ 

	static unsigned short j = 0;

	for ( std::list<Sprite*>::const_iterator i = this->sprites.begin();
		i != this->sprites.end(); i++ )
	{
		if ( !((*i)->isDirty()) )
		{
			continue;
		}
		
		Rectangle lastBBox ( (*i)->getLastBoundingBox() );
		
		BITMAP* black = create_system_bitmap ( lastBBox.w, 
			lastBBox.h );
		
		clear_to_color ( black, makecol(0, 0, 0) );
		//clear_to_color ( black, makecol(0, 0, 0) );
		
		//std::cout << "deleting" << std::endl ;
		blit ( black, screen, 0, 0, lastBBox.x, lastBBox.y,
			lastBBox.w, lastBBox.h );
	
		//rest(1000);
		
		//std::cout << "redrawing" << std::endl ;
		(*i)->draw ( screen );
		
		destroy_bitmap ( black );
	}



	return;
}


void Display::invalidateRect ( const Rectangle& rect )
{
	return;
}

} // namespace TV
