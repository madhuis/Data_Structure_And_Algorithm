#
# PROGRAM:    assign1
# PROGRAMMER: Ishan Madhu
# LOGON ID:   z1763923
# DATE DUE:   09/06/2015
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign1: assign1.o
	g++ $(CCFLAGS) -o assign1 assign1.o

# Rules to compile source code files to object code
assign1.o: assign1.cpp
	g++ $(CCFLAGS) -c assign1.cpp


# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign1
