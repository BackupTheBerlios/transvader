#ifndef PAGEFLIPPER_HXX
#define PAGEFLIPPER_HXX

#include <allegro.h>

#include "display.hxx"

namespace TV
{

class Pageflipper : public Display
{
        
        private:
               BITMAP *backbuf;
               BITMAP *framebuf;
               BITMAP *activebuf;
	       BITMAP *inactivebuf;

        public:
               Pageflipper ( int width, int height );
               ~Pageflipper();

               virtual BITMAP *getBitmap();
               void draw();


};

} /*namespace TV */

#endif



