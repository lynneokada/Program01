# Makefile - PROGRAM 01

# ====================================================

# defining "make" variables
CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

graph01:	graph01.o intVec.o
	${CC}  -o graph01  ${CFLAGS} graph01.o  intVec.o

graph01.o:	graph01.c  intVec.h
	${CC} -c ${CFLAGS} graph01.c

intVec.o:	intVec.c  intVec.h
	${CC}  -c  ${CFLAGS} intVec.c

clean :
	- rm *.o graph01