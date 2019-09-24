#TODO: fix for master header

TOPDIR=..

CC=g++
MAIN = $(TOPDIR)/build/main
TARGET=main
SOURCEDIR=$(TOPDIR)/src

# Sources definition
SOURCES=$(wildcard $(SOURCEDIR)/*.cc)

# Includes definition
INCLUDE=-I $(TOPDIR)/include

VPATH=$(SOURCEDIR)
OBJ=$(patsubst $(SOURCEDIR)/%.cc,./obj/%.o,$(SOURCES))


# Compiler flags
CFLAGS = ${INCLUDE} -g -c

all: dir $(TARGET)

dir:
	mkdir -p obj

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(OBJ): ./obj/%.o : $(SOURCEDIR)/%.cc
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ./obj/*.o $(TARGET)
