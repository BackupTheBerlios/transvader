#ifndef DISPLAY_HXX
#define DISPLAY_HXX

#include <allegro.h>

namespace TV
{

class Display
{

      public:
        Display();
	virtual ~Display();

	virtual BITMAP *getBMP() = 0;
	virtual void draw() = 0;

};

} // namespace TV

#endif
