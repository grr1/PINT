#TODO: implement master header functionality (?)

TOPDIR=..

CC=g++
MAIN = $(TOPDIR)/build/main
TARGET=main
SOURCEDIR=$(TOPDIR)/src
OBJDIR=./obj

# Sources definition
SOURCES=$(wildcard $(SOURCEDIR)/*.cc)

# Includes definition
INCLUDE=-I $(TOPDIR)/include

VPATH=$(SOURCEDIR)
OBJ=$(patsubst $(SOURCEDIR)/%.cc,$(OBJDIR)/%.o,$(SOURCES))


# Compiler flags
CFLAGS = ${INCLUDE} -g -c

all: dirs $(TARGET)

dirs: $(OBJDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

$(OBJ): ./obj/%.o : $(SOURCEDIR)/%.cc
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ./obj/*.o $(TARGET)
