#include "dragobject.hxx"


namespace TV
{

namespace Editor
{


DragObject::DragObject ( const char* mimeType, QWidget* dragSource, const char* name )
	: QStoredDrag ( mimeType, dragSource, name )
{
}


DragObject::DragObject ( QWidget* dragSource, const char* name)
	: QStoredDrag ( "application/x-transvader", dragSource, name )
{
}


DragObject::~DragObject()
{
}


} // ns Editor

} // ns TV

