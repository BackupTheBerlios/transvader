#ifndef EDITOR_PALETTE_HXX
#define EDITOR_PALETTE_HXX

#include <qiconview.h>
#include <qdragobject.h>

#include "dragobject.hxx"
#include "iconviewitem.hxx"

namespace TV
{

namespace Editor
{


class Palette : public QIconView
{
	Q_OBJECT
	
	public:
		Palette ( QWidget * parent = 0, const char * name = "Object Palette" );
		~Palette();
	
	protected:
		QDragObject* dragObject();
	
	private:
};


} // ns Editor

} // ns TV

#endif
