#ifndef EDITOR_ICONVIEWITEM_HXX
#define EDITOR_ICONVIEWITEM_HXX

#include <qiconview.h>

#include "editorobject.hxx"

namespace TV
{

namespace Editor
{


class IconViewItem : public QIconViewItem
{
	public:
		IconViewItem ( QIconView* parent = 0 );
		~IconViewItem();
	
	protected:
		TV::Editor::Object contents;
};


} // ns Editor

} // ns TV

#endif
