#
# PROGRAM:    Assignment 7
# PROGRAMMER: Ishan Madhu
# LOGON ID:   z1763923
# DATE DUE:   11/06/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assignment7: assignment7.o
	g++ $(CCFLAGS) -o assignment7 assignment7.o

# Rules to compile source code files to object code
assignment7.o: assignment7.cc
	g++ $(CCFLAGS) -c assignment7.cc


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment7

