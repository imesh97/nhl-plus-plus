#
# CS3307 INDIVIDUAL ASSIGNMENT (Makefile)
# Build script for program compilation and clean up

# by: Imesh Nimsitha
# 2023/02/07
#

CXX = g++
PRE_FLAGS = -Wall -g -std=c++11
POST_FLAGS = -lcurl
EXEC = main
OBJS = main.o game.o request.o

${EXEC}: ${OBJS}
	${CXX} ${PRE_FLAGS} -o ${EXEC} ${OBJS} ${POST_FLAGS}

main.o: main.cpp
	${CXX} ${PRE_FLAGS} -c main.cpp

game.o: game.cpp game.h
	${CXX} ${PRE_FLAGS} -c game.cpp

request.o: request.cpp request.h
	${CXX} ${PRE_FLAGS} -c request.cpp

clean:
	rm -f ${EXEC} ${OBJS}
