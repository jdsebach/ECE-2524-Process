HEAD := Process.hpp
SRC := process_test.cpp Process.cpp $@
CC := g++
CFLAGS := -Wall -g -std=c++0x
process_test:
	${CC} ${CFLAGS} -o $@ ${HEAD} ${SRC}
