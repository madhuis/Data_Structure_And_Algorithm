#
# PROGRAM:    Assignment 4
# PROGRAMMER: Ishan Madhu
# LOGON ID:   z1763923
# DATE DUE:   10/1/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign4.exe: assign4.o
	g++ $(CCFLAGS) -o assign4.exe assign4.o

# Rules to compile source code files to object code
assign4.o: assign4.cpp
	g++ $(CCFLAGS) -c assign4.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4.exe


