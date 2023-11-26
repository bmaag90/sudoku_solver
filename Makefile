CC = g++
# https://stackoverflow.com/questions/30573481/how-to-write-a-makefile-with-separate-source-and-header-directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := build

EXE := $(BIN_DIR)/main
SRC := $(wildcard $(SRC_DIR)/*.cpp) # gets a list of all cpp files in the SRC directory
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) # or with pathsubst OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

CPPFLAGS := -Iinclude -MMD -MP -DDEBUG
# The -MMD -MP flags are used to generate the header dependencies automatically. We will use this later on to trigger a compilation when only a header changes.
CFLAGS   := -Wall
LDFLAGS  := -Llib
# LDLIBS   := -lm

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $(CPPFLAGS) $^ $(LDLIBS) -o $@
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)
	
# -include $(OBJ:.o=.d).