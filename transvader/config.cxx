/******************************************************************************
 *  rectangle.cxx
 *
 *  Implements rectangles.
 *
 *  Author: Michael Prinzinger, Leslie Polzer, Mark Roesel
 *  Created: 2004-06-27 / Last updated: 2004-06-27
 *  
 *  For licensing conditions see the file LICENSE which should be included
 *  within this distribution.
 ******************************************************************************/
#include "config.hxx" 

namespace TV
{ 
	Config::Config(int argc, char **argv)
	{
		int nextOption = 0;
		
		while(42)
		{		
		nextOption = getopt_long (argc, argv, "", "", int *indexptr)	
		}
		
	}
	
	Config::~Config()
	{
	
	}
	
	string getPerceptionTechnique()
	{
		return "schtringTanga";	
	}
	
	int getXRes()
	{
		return(0);
	}
	
	int getYRes()
	{
		return(0);
	}
	
	int getColorDepth()
	{
		return(0);
	}
}

int main(int argc, char **argv)
	{
		return(0);
	}
