# Makefile

CC=g++
CFLAGS=-c -Wall


SOURCES = ComputerConfiguration.cpp ComputerProductFactory.cpp ComputerProductInventory.cpp Display.cpp HardDisk.cpp ProductInventoryTest.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ProductInventoryTest
LIBPATH=../ProductInventoryLib/
LIBS=ProductInventory

all: $(SOURCES) $(EXECUTABLE)

ProductInventoryTest: $(OBJECTS)
	$(CC) -o $(EXECUTABLE) $(OBJECTS) -L$(LIBPATH) -l $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean
