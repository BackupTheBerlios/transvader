#ifndef DOUBLEBUFFER_HXX
#define DOUBLEBUFFER_HXX

#include <allegro.h>

#include "display.hxx"

namespace TV
{

class Doublebuffer : public Display
{
        
        private:
               BITMAP *buffer;

        public:
               Doublebuffer ( int width, int height );
               ~Doublebuffer();

               virtual BITMAP *getBitmap();
               void draw();


};

} /*namespace TV */

#endif



