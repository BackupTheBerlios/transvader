
#include <list>

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
	this->sprites.push_back ( sprite );
	this->old_sprites.push_back ( sprite->getBoundingBox() );
	
	return;
}

/**
 * optimize our list of dirty rectangles:
 * 	- unite overlapping rectangles (maybe only if not too many new objects have to be added) 
 */
void Display::optimize()
{
	return;
}


void Display::draw()
{
	return;
}


void Display::invalidateRect ( const Rectangle& rect )
{
	return;
}

} // namespace TV
