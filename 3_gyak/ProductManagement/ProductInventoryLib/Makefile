# Makefile

CC=g++
AR=ar
CFLAGS=-c -Wall


LIBSOURCES = CompositeProduct.cpp Product.cpp ProductFactory.cpp ProductInventory.cpp
LIBOBJECTS=$(LIBSOURCES:.cpp=.o)
LIBRARY=libProductInventory.a

all: $(LIBSOURCES) $(LIBRARY)

$(LIBRARY): $(LIBOBJECTS)
	$(AR) rcs $(LIBRARY) $(LIBOBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(LIBOBJECTS) $(LIBRARY)

.PHONY: all clean
