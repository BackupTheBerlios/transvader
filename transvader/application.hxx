// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer, Michael Prinzinger
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef APPLICATION_HXX
#define APPLICATION_HXX


namespace TV
{

class Application
{
	public:
		Application();
		virtual ~Application();
	
		virtual void run() = 0;

};

} // namespace TV

#endif
