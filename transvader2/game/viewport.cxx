/******************************************************************************
 *  viewport.cxx
 *
 *  Implements a viewport.
 *
 *  Author: Mark Roesel, Leslie Polzer
 *  Created: 2004-06-26 / Last updated: 2004-06-26
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/
 
#include "viewport.hxx"

namespace TV {

	Viewport::Viewport(Point& p, int w, int h)
		:
		Rectangle(p, w, h)
	{
		return;
	}


	Viewport::~Viewport()
	{
		return;
	}


	Point Viewport::translateCoords( const Point& p )
	{
		return Point(p.x-this->getP().x, p.y-this->getP().y);
	}
	
} // end of namespace TV
