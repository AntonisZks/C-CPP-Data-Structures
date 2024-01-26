CC = g++
CFLAGS = -g -Wall

OBJS = main.o

all: out

out: main.o
	$(CC) $(CFLAGS) main.o -o out

main.o: main.cpp array.hpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	del $(OBJS) out.exe
