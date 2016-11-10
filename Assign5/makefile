#
# PROGRAM:    assign5
# PROGRAMMER: Ishan Madhu
# LOGON ID:   z1763923
# DATE DUE:   October 18, 2015
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code to create executable file
assign5.exe: assign5.o assign5implement.o
	g++ $(CCFLAGS) -o assign5.exe assign5.o assign5implement.o

# Rules to compile source code files to object code
assign5.o: assign5.cpp assign5.h
	g++ $(CCFLAGS) -c assign5.cpp

assign5implement.o: assign5implement.cpp assign5.h
	g++ $(CCFLAGS) -c assign5implement.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign5.exe

