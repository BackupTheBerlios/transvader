// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer, Michael Prinzinger
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#ifndef EDITOR_HXX
#define EDITOR_HXX

#include <allegro.h>

#include <iostream>

#include "application.hxx"


namespace TV
{

class Editor : public Application
{
	public:
		Editor();
		virtual ~Editor();
	
		virtual void run();

	private:
		static void mouse_cb ( BITMAP* bmp, int mx, int my, void* data );
};

} // namespace TV

#endif
