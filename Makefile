.PHONY: all clean fclean re obj_directory

NAME = logo

CC = gcc

CFLAGS			= -Wall -Wextra -Werror -std=c11
INCLUDE_FLAGS 	= -I $(INC_DIR)

INC_DIR 	 = include
SRC_DIR		 = src
OBJ_DIR		 = obj

SOURCES = logo.c 
HEADER_FILES = logo.h 
			
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
HEADERS = $(addprefix $(INC_DIR)/, $(HEADER_FILES))

all: obj_directory $(NAME)

obj_directory:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< $(INCLUDE_FLAGS) -o $@

$(NAME): $(OBJECTS) 
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "${NAME} has been created."

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} has been deleted."

re: fclean all