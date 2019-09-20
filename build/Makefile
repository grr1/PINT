#TODO: make functional :)

TOPDIR=..

CC=gcc
MAIN = $(TOPDIR)/build/main
TARGET=main
SOURCEDIR=$(TOPDIR)/src

# Sources definition
SOURCE=$(SOURCEDIR)/main.cpp

# Includes definition
INCLUDE=-I$(TOPDIR)/include

# Compiler flags
CFLAGS = -o $(TARGET) ${INCLUDE}
SFLAGS = ${INCLUDE}

all: $(TARGET)

$(TARGET): main.o
	gcc -o main -I ../include $(SOURCE)
	# using -I changes the `include` directory, lets us keep pint.h somewhere else

main.o: ../src/main.cpp ../include/pint.hh
	gcc -c -o main.o ../src/main.cpp

clean:
	rm -f main.o main
