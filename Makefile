# CSE30 Makefile
# 
# EXE - objects we want to build
# OBJS - objects we want to compile (from c)
# 
# We provide a phony target clean to rm all the .o files
# 
# Run make to run with warnings
# Run make WARN= to run without warnings
# Run make DEBUG= to run without debug
# Run make DEBUG= WARN= to run without debug and warnings
# Run make clean to clean objects

EXE = poll_lookup
OBJS = poll_lookup.o parse_opts.o strip_date.o hash.o
CC = gcc
DEBUG = -g
WARN = -Wall -Wextra
CFLAGS = -I. -std=c11 $(DEBUG) $(WARN)
LIBS = 

.PHONY: clean

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

poll_lookup.o: poll_lookup.h

clean:
	rm -f $(EXE) $(OBJS)
