# Compiler settings
CC = g++                # The compiler to use (g++ for C++)
CFLAGS = -std=c++17 -Wall -O2  # Compilation flags (standard C++17, all warnings, optimization)
LDFLAGS =                 # Linker flags (empty for now)

# Source files
SRC = yiy.cpp            # List of source files (add more if needed)

# Object files (derived from the source files)
OBJ = $(SRC:.cpp=.o)

# Executable file
EXEC = yiy                # The final executable will be named 'yiy'

# Default rule (compile and link)
all: $(EXEC)

# Rule to compile .cpp files into .o files
$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(EXEC)

# Clean the build (remove object files and executable)
clean:
	rm -f $(OBJ) $(EXEC)

# Install the executable globally
install: $(EXEC)
	sudo mv $(EXEC) /usr/local/bin/
	sudo chmod +x /usr/local/bin/$(EXEC)

# Rebuild everything
rebuild: clean all

# Show help
help:
	@echo "Usage:"
	@echo "  make        - Compile the project"
	@echo "  make install - Install the executable globally"
	@echo "  make clean   - Remove object files and executable"

