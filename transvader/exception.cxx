#include <stdlib.h>		/* abort() */
#include <string.h>
#include <stdio.h>
#include <allegro.h>

#include "exception.hxx"


Exception::Exception ( const char* error, const severity_t severity )
{
	this->error = strdup(error);
	this->severity = severity;
	
	return;
}

Exception::~Exception() {}


void Exception::handle()
{
	this->toConsole();

	if ( this->severity == ERR_FATAL )
	{
		allegro_message ( "transvader: Terminating due to fatal error.\n" );
	
		exit(1);	
	}
	
	return;
}


void Exception::toConsole()
{
	allegro_message ( "transvader: %s: %s\n", this->getSeverityString(),
		this->getErrorString() );
		
	return;
}


char* Exception::getErrorString()
{
	return ( this->error );
}


severity_t Exception::getSeverity()
{
	return ( this->severity );
}


char* Exception::getSeverityString()
{
	char* errmsg;

	switch ( this->severity )
	{
		case ERR_FATAL:
			errmsg = strdup("Fatal error");
		break;	
	
		case ERR_ERROR:
			errmsg = strdup("Non-fatal error");
		break;
		
		case ERR_WARNING:
			errmsg = strdup("Warning");
		break;
		
		default:
			errmsg = "Undefined exception";
	}
	
	return errmsg;
}

