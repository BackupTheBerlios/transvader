// This file is a part of the Transvader sourcecode. Transvader is a free Asteroids clone distributed under GPL
// Copyright (C) 2004  Leslie P. Polzer
// The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
// This program is distributed under the GNU General Public License, for details read the file LICENSE 
// at the root of this distribution

#include <allegro.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>

#include "exception.hxx"
#include "game.hxx"
#include "rectangle.hxx"

using TV::Game;
using TV::Exception;
using TV::Rectangle;
using namespace std;
using namespace TV;

int main ( int argc, char** argv )
{
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
        Rectangle *blub = new Rectangle(2,3,4,5);
        Rectangle *test = new Rectangle(*blub);

        x = test->getX();
        y = test->getY();
        w = test->getW();
        h = test->getH();

	cout << "\nx: " << x << "  y: " << y << "  w: " << w << "  h: " << h  << endl;

        getch();
	return(0);
}

END_OF_MAIN()
