#
# PROGRAM:    assignment6
# PROGRAMMER: Ishan Madhu
# LOGON ID:   z1763923
# DATE DUE:   October 27, 2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assignment6main: assignment6main.o assignment6.o assign5implement.o
	g++ $(CCFLAGS) -o assignment6main assignment6main.o assign5implement.o assignment6.o

# Rules to compile source code files to object code
assignment6main.o: assignment6main.cc assignment6.h
	g++ $(CCFLAGS) -c assignment6main.cc

assign5implement.o: assign5implement.cpp assign5.h
	g++ $(CCFLAGS) -c assign5implement.cpp

assignment6.o: assignment6.cc assignment6.h
	g++ $(CCFLAGS) -c assignment6.cc

assignment6.h: assign5.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment6main

