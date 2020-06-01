CC=g++
CPPFLAGS=-g -Wall 
LIBS=-std=c++11

TARGET=main
OBJS=main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^
	
main.o: main.cpp

clean:
	rm -f *.o
