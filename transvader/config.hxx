/******************************************************************************
 *  config.hxx
 *
 *  Implements rectangles.
 *
 *  Author: Michael Prinzinger, Leslie Polzer, Mark Roesel
 *  Created: 2004-06-27 / Last updated: 2004-06-27
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/

#ifndef CONFIG_HXX
#define CONFIG_HXX
#include <string>
#include <unistd.h>

namespace TV
{
	
class Config
{
 	public: 

		Config(int argc, char **argv);
		~Config();
		string getPerceptionTechnique();
		
		int getXRes();
		int getYRes();
		int getColorDepth();
		
	
	private:
		char* option;
		std::string perception_technique;
		int gfx_mode[2];

		static struct option long_options[] =
		{
		   {"perception-technique", required_argument, 0, 'p'},
		   {"gfx_mode",				required_argument, 0, 'g'},
		   {0, 0, 0, 0}
		 };		
};

}

#endif
