CC = gcc
AR = ar
FLAGS = -Wall -g
OBJECTS_MAIN = Main.o
OBJECTS_LIB = StrList.o

all: my_libs StrList

StrList: $(OBJECTS_MAIN) my_lib.a
	$(CC) $(FLAGS) -o StrList $(OBJECTS_MAIN) my_lib.a

Main.o: Main.c StrList.h
	$(CC) $(FLAGS) -c -fPIC Main.c -o Main.o

StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c -fPIC StrList.c -o StrList.o

my_lib.a: $(OBJECTS_LIB)
	$(AR) -rcs my_lib.a $(OBJECTS_LIB)

my_libs: my_lib.a

clean:
	rm -f *.o *.a *.so StrList
