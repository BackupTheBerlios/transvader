// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#include <allegro.h>

#include <libgen.h>	//basename

#include <string>

#include "exception.hxx"
#include "application.hxx"
//#include "editor.hxx"
#include "game.hxx"

using TV::Application;
using TV::Game;
//using TV::Editor;
using TV::Exception;

int main ( int argc, char** argv )
{
	std::string appname(basename(argv[0]));
	Application *app;
	
	try
	{
	
/*	if ( appname == "transvader-editor" )
		{
			app = new Editor();
		}
		else*/
		{	
			app = new Game();
		}
		
		app->run();
		
		delete app;
	}
	catch ( Exception& ex)
	{
		ex.handle();
	}
	
	return(0);
}

END_OF_MAIN()
