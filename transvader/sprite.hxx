#ifndef SPRITE_HXX
#define SPRITE_HXX

class Sprite
{
	private:
		unsigned short x, y;
		unsigned short size_x, size_y;
	
	public:
		Sprite();
		virtual ~Sprite();
	
		virtual void draw() const = 0;
}

#endif
