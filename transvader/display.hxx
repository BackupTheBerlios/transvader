#ifndef DISPLAY_HXX
#define DISPLAY_HXX


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
