#
# PROGRAM:    Assignment 9
# PROGRAMMER: ISHAN MADHU
# LOGON ID:   z1763923
# DATE DUE:   12.02.2015
#

# Compiler variables
CC = g++ 
CCFLAGS = -Wall -std=c++11
CNAME = assignment9

$(CNAME).exe: $(CNAME).o
	$(CC) $(CCFLAGS) -o $(CNAME).exe $(CNAME).o

$(CNAME).o: $(CNAME).cc
	$(CC) $(CCFLAGS) -c $(CNAME).cc

clean:
	-rm *.o $(CNAME).exe
