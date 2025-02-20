# Compiler (use clang by default, or switch to gcc-13 if using Homebrew)
CC = /opt/homebrew/opt/llvm/bin/clang-19
# CC = gcc-13  # Uncomment if using Homebrew-installed GCC

# Compiler flags
CFLAGS = -g -DOSX -Wno-deprecated-register -Wno-deprecated-declarations -Wno-shift-op-parentheses -Wno-parentheses-equality
INCFLAGS = -I/opt/homebrew/include 

# Source files (C files in the current directory)
SRCS = stackS.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Output binary name
TARGET = ex5_1 

# Default rule: compile everything
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCFLAGS) $(OBJS) -o $(TARGET)

# Compiling source files into object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)
