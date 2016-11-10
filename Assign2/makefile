#
# PROGRAM:    assign2
# PROGRAMMER: Ishan Madhu
# LOGON ID:   z1763923
# DATE DUE:   09/11/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign2: assign2.o
	g++ $(CCFLAGS) -o assign2 assign2.o

# Rules to compile source code files to object code
assign2.o: assign2.cpp
	g++ $(CCFLAGS) -c assign2.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign2

