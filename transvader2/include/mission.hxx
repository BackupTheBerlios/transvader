/******************************************************************************
 *  mission.hxx
 *
 *  Missions.
 *
 *  Author: Leslie P. Polzer, 
 *  Created: 2004-11-06 / Last updated: 2004-11-06
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/
#ifndef MISSION_HXX
#define MISSION_HXX

#include <string>

#include "map.hxx"


using std::string;


namespace TV
{

class Mission
{
	public:
		Mission();
		~Mission;

		void setNumber ( int number );
		int getNumber();

		void setTitle ( string title );
		string getTitle();
	
		void setBriefing ( string briefing );
		string getBriefing();
	
		void setAuthor ( string author );
		string getAuthor();

		void setImage ( string image );
		string getImage();
	
	private:
		int number;
	
		string author;
		string title;
		string briefing;
		string image;
	
		Map* map;
};


} // ns TV

#endif
