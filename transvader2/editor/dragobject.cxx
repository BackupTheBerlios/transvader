#ifndef EDITOR_DRAGOBJECT_HXX
#define EDITOR_DRAGOBJECT_HXX

#include <qdragobject.h>


namespace TV
{

namespace Editor
{


class DragObject : public QStoredDrag
{
	Q_OBJECT
		
	DragObject();
	~DragObject();
};


} // ns Editor

} // ns TV

#include "dragobject.moc"

#endif
