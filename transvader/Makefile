# Makefile for Transvader (Leslie 2004)

BIN=transvader
OBJ=main.o sprite.o exception.o tv.o
SRC=main.cxx sprite.cxx exception.cxx tv.cxx

ALLEG_CXXFLAGS=`allegro-config --cflags`
# linker flags need to be fixed because allegro-config doesn't generate output
# suitable for explicit (i.e. direct ld-call-wise) linking
ALLEG_LDFLAGS=`allegro-config --libs|sed -e 's!-Wl,!!'` \
		-e _mangled_main_address -lstdc++ -lc

CXX=g++
CXXFLAGS=-ggdb -Wall $(ALLEG_CXXFLAGS)
LDFLAGS=$(ALLEG_LDFLAGS)

all: transvader

clean:
	rm -f $(BIN) *.o

%.o: %.cxx
	$(CXX) $(CXXFLAGS) -c $<

transvader: $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(BIN)
