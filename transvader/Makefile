# Makefile for Transvader 
# Copyright (C) 2004  Leslie P. Polzer
# The full copyright notice can be found in the file DISCLAIMER at the root of this distribution.
# This program is distributed under the GNU General Public License, for details read the file LICENSE 
# at the root of this distribution

BIN=transvader
OBJ=main.o sprite.o player.o exception.o game.o rectangle.o backdrop.o foe.o \
	display.o
SRC=main.cxx sprite.cxx player.cxx exception.cxx game.cxx rectangle.cxx \
	backdrop.cxx foe.cxx display.cxx
    
    

ALLEG_CXXFLAGS=`allegro-config --cflags`
# linker flags need to be fixed because allegro-config doesn't generate output
# suitable for separate (i.e. direct ld-call-wise) linking
ALLEG_LDFLAGS=`allegro-config --libs` #|sed -e 's!-Wl,!!'` \
		#-e _mangled_main_address 

CXX=g++
CXXFLAGS=-O2 -pg -ggdb -Wall $(ALLEG_CXXFLAGS)
LDFLAGS=-lm -pg $(ALLEG_LDFLAGS)

all: transvader

clean:
	rm -f $(BIN) *.o

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $<

%.cxx: %.hxx

transvader: $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) -o $(BIN)

