SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -O2 -I$(INCLUDE_DIR)
LDFLAGS = 

TARGET = clox

# Build the target from object files
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile .c files into .o files, with dependency generation
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Include dependency files generated during compilation
-include $(OBJS:.o=.d)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

