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
