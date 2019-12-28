# TODO: add gprof analysis

TOP_DIR=..
SRC_DIR=$(TOP_DIR)/src
INC_DIR=$(TOP_DIR)/inc
TEST_SRC_DIR=$(TOP_DIR)/testsrc
BUILD_DIR=.
TEST_DIR=$(BUILD_DIR)/tests
OBJ_DIR=$(BUILD_DIR)/obj

CC=g++
CFLAGS= -I ${INC_DIR} -g -Wall -Wextra -pedantic -c
#LDFLAGS=

# Source definitions
SRC=$(wildcard $(SRC_DIR)/*.cc)
TEST_SRC=$(wildcard $(TEST_SRC_DIR)/*.cc)

# Object definitions
OBJ=$(patsubst $(SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(SRC))
TEST_OBJ=$(patsubst $(TEST_SRC_DIR)/%.cc,$(OBJ_DIR)/%.o,$(TEST_SRC))

TARGET=$(patsubst $(TEST_SRC_DIR)/%.cc,$(TEST_DIR)/%,$(TEST_SRC))

# Require build directories and targets
all: dirs $(TARGET)

# Make directories
dirs: $(OBJ_DIR) $(TEST_DIR)

$(OBJ_DIR) $(TEST_DIR):
	mkdir -p $@

# Link each target from correct obj files
$(TARGET): $(TEST_DIR)/% : $(OBJ) $(OBJ_DIR)/%.o
	$(CC) $(LDFLAGS) $^ -o $@

# Compile all PINT objects
$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) $< -o $@

# Compile all test main objects
$(TEST_OBJ): $(OBJ_DIR)/%.o : $(TEST_SRC_DIR)/%.cc
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f -r $(OBJ_DIR) $(TEST_DIR)
