// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

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


void Exception::handle() const
{
	this->toConsole();

	if ( this->severity == ERR_FATAL )
	{
		allegro_message ( "transvader: Terminating due to fatal error.\n" );
	
		exit(1);	
	}
	
	return;
}


void Exception::toConsole() const
{
	allegro_message ( "transvader: %s: %s\n", this->getSeverityString(),
		this->getErrorString() );
		
	return;
}


char* Exception::getErrorString() const
{
	return ( this->error );
}


severity_t Exception::getSeverity() const
{
	return ( this->severity );
}


char* Exception::getSeverityString() const
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

