// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#include <allegro.h>

#include "exception.hxx"
#include "tv.hxx"


int main ( int argc, char** argv )
{
	TV* tv;

	try
	{
		tv = new TV();
	}
	catch ( Exception& ex )
	{
		ex.handle();
	}
	
	tv->run();
	
	return(0);
}

END_OF_MAIN()
