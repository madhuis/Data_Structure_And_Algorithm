#
# PROGRAM:    Assignment 3
# PROGRAMMER: Ishan Madhu
# LOGON ID:   z1763923
# DATE DUE:   9/21/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign3: assign3.o
	g++ $(CCFLAGS) -o assign3 assign3.o

# Rules to compile source code files to object code
assign3.o: assign3.cpp
	g++ $(CCFLAGS) -c assign3.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign3

