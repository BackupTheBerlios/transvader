
#include "display.hxx"

namespace TV
{

Display::Display();
virtual Display::~Display();

virtual BITMAP *Display::getBMP()
{}
virtual void Display::draw()
{}

};

} // namespace TV
