#ifndef EDITOR_EDITOROBJECT_HXX
#define EDITOR_EDITOROBJECT_HXX

#include <qimage.h>
#include <qpixmap.h>
#include <qwmatrix.h>

#include "sprite.hxx"


namespace TV
{

namespace Editor
{


class Object 
{
	public:
		Object();
		~Object();
	
	protected:
		QImage image;
		QPixmap icon;
		QWMatrix matrix;
	
		TV::Sprite* sprite;
};


} // ns Editor

} // ns TV

#endif
