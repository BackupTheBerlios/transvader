#ifndef PAGEFLIPPER_HXX
#define PAGEFLIPPER_HXX

#include <allegro.h>

#include "display.hxx"

namespace TV
{

class Pageflipper : public Display
{
        
        private:
               BITMAP *page[2];
		unsigned short pagenum;

        public:
               Pageflipper ( int width, int height );
               ~Pageflipper();

               virtual BITMAP *getBitmap();
               void draw();


};

} /*namespace TV */

#endif



