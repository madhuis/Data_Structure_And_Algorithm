#
# PROGRAM:    Assign 8
# PROGRAMMER: Ishan Madhu
# LOGON ID:   z1763923
# DATE DUE:   11.16.15
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assignment8: assignment8.o
	g++ $(CCFLAGS) -o assignment8 assignment8.o

# Rules to compile source code files to object code
assignment8.o: assignment8.cc
	g++ $(CCFLAGS) -c assignment8.cc


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment8

