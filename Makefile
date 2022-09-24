CC = g++
CFLAGS = -std=gnu++17 -Wall -Wextra -Wpedantic -O3
INC_DIR = .
LIBS = -lm
SFML = -lsfml-graphics -lsfml-window -lsfml-system

#vsge lib
LIB_DIR = lib
OBJ_DIR_LIB = obj
OBJS_LIB = $(addprefix $(OBJ_DIR_LIB)/, vsge_common.o vsge_drawable.o vsge_shapes.o vsge_core.o vsge_loop.o vsge_window.o)

#examples
SRC_DIR = examples
OBJ_DIR = obj
OBJS_EXAMPLES = $(addprefix $(OBJ_DIR)/, test.o)

NAME = prototype

all: pre $(OBJS_LIB) $(OBJS_EXAMPLES)
	@$(CC) $(CFLAGS) $(OBJS_LIB) $(OBJS_EXAMPLES) -o $(NAME) $(LIBS) $(SFML)

pre:
	@if [ ! -d "$(OBJ_DIR)" ]; then mkdir $(OBJ_DIR); fi;
	@if [ ! -d "$(OBJ_DIR_LIB)" ]; then mkdir $(OBJ_DIR_LIB); fi;

$(OBJ_DIR_LIB)/%.o: $(LIB_DIR)/%.cpp
	@$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) $(CFLAGS) -c -I$(INC_DIR) $< -o $@

clean:
	@if [ -d "$(OBJ_DIR)" ]; then rm -r -f $(OBJ_DIR); fi;
	@if [ -d "$(OBJ_DIR_LIB)" ]; then rm -r -f $(OBJ_DIR_LIB); fi;

distclean: clean
	@rm -f $(NAME)