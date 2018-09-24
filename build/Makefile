#Compiler
CC = g++

#Compiler flags
CFLAGS = -Wall -g -std=c++11

# Include directory
IDIR = -I../include/

# SRC directory
SRCDIR = ../src/

#SRC targets
SRC = AVL

# TEST directory
TESTDIR = ../test/

TEST = main

#MISC directory
MISCDIR = ../misc/

MISC = unittest

#OBJ directory
OBJDIR = ../obj/

all : $(SRC) $(TEST) $(MISC)
	@$(CC) $(CFLAGS) $(IDIR) -o tree $(OBJDIR)$(SRC).o $(OBJDIR)$(TEST).o
	@$(CC) $(CFLAGS) $(IDIR) -o utest $(OBJDIR)$(SRC).o $(OBJDIR)$(MISC).o

$(TEST) :
	@$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$@.cpp
	@mv $(TEST).o $(OBJDIR)

$(SRC) :
	@$(CC) $(CFLAGS) $(IDIR) -c $(SRCDIR)$@.cpp
	@mv $(SRC).o $(OBJDIR)

$(MISC) :
	@$(CC) $(CFLAGS) $(IDIR) -c $(MISCDIR)$@.cpp
	@mv $(MISC).o $(OBJDIR)

run_unittest:
	@./utest

clean:
	@rm -f $(OBJDIR)*.o
	@rm tree
	@rm utest
	@rm -f $(MISCDIR)/output/*.txt

run:
	@./tree
