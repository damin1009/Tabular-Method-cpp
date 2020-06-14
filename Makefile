CC=g++
FLAGS=-g -o 
LIBS=-std=c++11

TARGET=main
FS=main.cpp

all: $(TARGET)

$(TARGET): $(FS)
	$(CC) $(FLAGS) $@ $^ $(LIBS)

MTerm_test: MTerm.h MTerm.cpp MTerm_test.cpp
	$(CC) $(FLAGS) $@ $^ $(LIBS)

PrimeI_test: MTerm.h MTerm.cpp PrimeI.h PrimeI.cpp PrimeI_test.cpp
	$(CC) $(FLAGS) $@ $^ $(LIBS)

PiListContainer_test: MTerm.h MTerm.cpp PrimeI.h PrimeI.cpp PiListContainer.h PiListContainer.cpp PiListContainer_test.cpp
	$(CC) $(FLAGS) $@ $^ $(LIBS)

PiGenerator_test: MTerm.h MTerm.cpp PrimeI.h PrimeI.cpp PiListContainer.h PiListContainer.cpp PiGenerator.h PiGenerator.cpp PiGenerator_test.cpp
	$(CC) $(FLAGS) $@ $^ $(LIBS)

clean:
	rm -f *.o
