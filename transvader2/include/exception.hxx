// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef EXCEPTION_HXX
#define EXCEPTION_HXX

#include <string>


namespace TV
{

typedef enum
{
	ERR_FATAL,
	ERR_ERROR,
	ERR_WARNING
} severity_t;


class Exception
{
	private:
		std::string error;
		severity_t severity;
	
	public:
		Exception ( const std::string error = "Unknown Error",
			const severity_t severity = ERR_FATAL );
		~Exception();

		void handle() const;
		void toConsole() const;
		
		/* accessor functions */
		std::string getErrorString() const;
		severity_t getSeverity() const;
		std::string getSeverityString() const;
};

}

#endif
