#include <allegro.h>
#include "exception.hxx"
#include "pageflipper.hxx"


namespace TV
{

Pageflipper::Pageflipper(int width, int height)
{

        backbuf = create_video_bitmap(width, height);
        framebuf = create_video_bitmap(width, height);
        clear(framebuf);

        if ((!backbuf) || (!framebuf))
        {
	   throw Exception ( std::string("Unable to create two video memory buffer\n")
	   + std::string(")"), ERR_FATAL );
        }

        activebuf = framebuf;

}

Pageflipper::~Pageflipper()
{
        destroy_bitmap(backbuf);
        destroy_bitmap(framebuf);
}

void Pageflipper::draw()
{
     !DRAW PLEASE!
     show_video_bitmap(activebuf);

     if (activebuf == backbuf)
        activebuf = framebuf;
     else
        activebuf = backbuf;

     return;
}


virtual BITMAP *Pageflipper::getBMP();

} /*namespace TV */



