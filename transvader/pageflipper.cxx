
#include <allegro.h>

#include "exception.hxx"
#include "pageflipper.hxx"


namespace TV
{

Pageflipper::Pageflipper ( int width, int height )
{

        backbuf = create_video_bitmap ( width, height );
        if ( backbuf == NULL )
        {
	   throw Exception ( std::string("Unable to create buffer 1.\n")
	   	+ std::string(")"), ERR_FATAL );
        }
	
        framebuf = create_video_bitmap ( width, height );
        if ( framebuf == NULL )
        {
	   throw Exception ( std::string("Unable to create buffer 2.\n")
	   	+ std::string(")"), ERR_FATAL );
        }

        clear(framebuf);

        activebuf = framebuf;

}


Pageflipper::~Pageflipper()
{
        destroy_bitmap(backbuf);
        destroy_bitmap(framebuf);
}


void Pageflipper::draw()
{
     show_video_bitmap(activebuf);

     if (activebuf == backbuf)
        activebuf = framebuf;
     else
        activebuf = backbuf;

     return;
}


BITMAP *Pageflipper::getBMP()
{
	return ( this->activebuf );
}

} /*namespace TV */



