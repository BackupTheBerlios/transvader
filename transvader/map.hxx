/******************************************************************************
 *  map.hxx
 *
 *  Virtual map with objects on it.
 *
 *  Author: Leslie P. Polzer, 
 *  Created: 2004-11-06 / Last updated: 2004-11-06
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/
#ifndef MAP_HXX
#define MAP_HXX


#include <list>

#include "sprite.hxx"


using std::list;

namespace TV
{

class Map
{
	public:
		Map();
		Map( int width, int height );
		~Map();

	private:
		int width;
		int height;
		list <Sprite*> objects;
};


} // ns TV

#endif
