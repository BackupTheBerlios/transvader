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

        public:
               Pageflipper ( int width, int height );
               ~Pageflipper();

               virtual BITMAP *getBMP();
               void draw();


};

} /*namespace TV */

#endif



