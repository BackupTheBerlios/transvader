/******************************************************************************
 *  viewport.hxx
 *
 *  Implements a viewport.
 *
 *  Author: Mark Roesel, Leslie Polzer, 
 *  Created: 2004-06-26 / Last updated: 2004-06-26
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/

#ifndef VIEWPORT_HXX
#define VIEWPORT_HXX

class Viewport : public Rectangle {

	public:
		Viewport(Point& p, int w, int h);
	
		~Viewport();
	
		Point& translateCoords( Point& p );
}

#endif
