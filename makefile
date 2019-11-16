TARGET_EXEC ?= Tetravex
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src
CC = g++ -std=c++11 -pthread

SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CC) -c $< -o $@

MKDIR_P ?= mkdir -p
