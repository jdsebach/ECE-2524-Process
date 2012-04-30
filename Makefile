CC := g++
CFLAGS := -Wall -g
SRC := process_test.cpp Process
OBJ := ${SRC:.cpp=.o}

all: process_test child

process_test: ${OBJ}
	${CC} $(CFLAGS) -o $@ ${OBJ}

child: child.o
	${CC} $(CFLAGS) -o $@ child.o

%.o : %.cpp
	$(CC) $(CFLAGS) -MD -o $@ -c $<
	@cp $*.d $*.P; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $*.P >> $*.d; \
	rm -f $*.P

clean: -rm *.o *.d *~
