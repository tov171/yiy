# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

# Target executable
TARGET = yiy

# Source files and object files
SRCS = main.cpp yiy.cpp
OBJS = main.o yiy.o

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

