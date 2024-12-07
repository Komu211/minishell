# Name of the library
NAME		=	minishell

# Directories
SRC_DIR			=	src
OBJ_DIR			=	obj
INC_DIR			=	inc
WRAPPER_DIR		=	$(SRC_DIR)/wrappers

# Libft
LIBFT_DIR		=	libft
LIBFT_INC_DIR	=	$(LIBFT_DIR)/inc
LIBFT			=	$(LIBFT_DIR)/libft.a
LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft

# Compiler and flags
CC				=	cc
INCLUDES		=	-I $(INC_DIR) -I $(LIBFT_INC_DIR)
CFLAGS			=	-Wall -Wextra -Werror $(INCLUDES)
DEBUG_FLAGS		=	-g -fsanitize=address -fcolor-diagnostics -fansi-escape-codes
RM				=	rm -f

# Source files and corresponding object files
WRAPPERS		= wrappers.c

WRAPPERS		:=	$(addprefix $(WRAPPER_DIR)/, $(WRAPPERS))

SRCS			= $(SRC_DIR)/main.c \
				$(WRAPPERS) \

OBJS			=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

# Link object files and libft to create the final executable
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(LIBFT_FLAGS) -o $(NAME) $(OBJS)
	@echo "Compiling $(NAME) project"

debug: fclean $(LIBFT) $(OBJS)
	@$(CC) $(DEBUG_FLAGS) $(CFLAGS) $(LIBFT_FLAGS) -o $(NAME) $(OBJS)
	@echo "Compiling $(NAME) project with debug flags"

docker: fclean $(LIBFT) $(OBJS)
	@$(CC) -g $(CFLAGS) $(LIBFT_FLAGS) -o $(NAME) $(OBJS)
	@echo "Compiling $(NAME) project with debug flags for docker"

# Compile source files into object files in the obj/ folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create the obj/ directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))
	@echo "Creating folders for object files"

# Build the libft library by calling its Makefile
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	@echo "Creating libft"

# Clean object files from both fdf and libft
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Deleting $(NAME) objects"

# Full clean: also remove the executable and libft objects
fclean: clean
	@$(RM) $(NAME)
	@echo "Deleting $(NAME) executable"

# Rebuild everything
re: fclean all

# Norm rule
norm:
	@echo "Norminette for $(NAME):"
	@-norminette src

# PHONY prevents conflicts with files named like the targets
.PHONY: all clean fclean re
