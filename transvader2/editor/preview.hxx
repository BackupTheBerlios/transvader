#ifndef EDITOR_PREVIEW_HXX
#define EDITOR_PREVIEW_HXX

#include <qcanvas.h>
#include <qpainter.h>
#include <qbitmap.h>
#include <qimage.h>
#include <qdragobject.h>


namespace TV
{

namespace Editor
{


class Preview : public QCanvasView
{
	Q_OBJECT

	public:
		Preview ( QWidget *parent = 0, const char *name = "PreviewArea",
			WFlags f = 0 );
	
		virtual ~Preview();
		
	protected:
		void dragEnterEvent ( QDragEnterEvent* event );
		void dropEvent ( QDropEvent *event );
		//void contentsDropEvent ( QDropEvent *event );

		void drawMaskedQImage ( const QPoint& pos, const QImage& image );
		
	private:
};


} // ns Editor

} // ns TV

#endif
