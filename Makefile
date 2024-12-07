# Name of the library
NAME		=	minishell

# Directories
SRC_DIR			=	src
OBJ_DIR			=	out
INC_DIR			=	includes
WRAPPER_DIR		=	$(SRC_DIR)/wrapper
GC_DIR			=	$(SRC_DIR)/gc
ERROR_DIR		=	$(SRC_DIR)/error
ENV_DIR			=	$(SRC_DIR)/env
UTILS_DIR		=	$(SRC_DIR)/utils
AST_DIR			=	$(SRC_DIR)/ast

# Libft
LIBFT_DIR		=	libft
LIBFT_INC_DIR	=	$(LIBFT_DIR)/inc
LIBFT			=	$(LIBFT_DIR)/libft.a
LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft

# Compiler and flags
CC				=	cc
INCLUDES		=	-I$(INC_DIR) -I$(LIBFT_INC_DIR)
READLINE_FLAGS	=	-lreadline -ltermcap
CFLAGS			=	-Wall -Wextra -Werror $(INCLUDES)
DEBUG_FLAGS		=	-g -fsanitize=address
RM				=	rm -f

# Source files and corresponding object files
WRAPPER			= gc_malloc.c gc_calloc.c gc_realloc.c gc_free.c gc_getcwd.c
GC				= gc_holder.c gc_add.c gc_remove.c gc_empty.c
ERROR			= error_handler.c
ENV				= env.c env_empty.c
UTILS			= gc_strdup.c gc_strjoin.c gc_split.c gc_substr.c
AST				= ast_build.c ast_init.c ast_new_node.c

WRAPPER			:=	$(addprefix $(WRAPPER_DIR)/, $(WRAPPER))
GC				:=	$(addprefix $(GC_DIR)/, $(GC))
ERROR			:=	$(addprefix $(ERROR_DIR)/, $(ERROR))
ENV 			:=	$(addprefix $(ENV_DIR)/, $(ENV))
UTILS			:=	$(addprefix $(UTILS_DIR)/, $(UTILS))
AST				:=	$(addprefix $(AST_DIR)/, $(AST))

SRCS			= $(SRC_DIR)/main.c $(SRC_DIR)/cleanup.c \
				$(WRAPPER) \
				$(GC) \
				$(ERROR) \
				$(ENV) \
				$(UTILS) \
				$(AST)

OBJS			=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

# Link object files and libft to create the final executable
$(NAME): $(LIBFT) $(OBJS)
	@echo "Compiling $(NAME) project"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(READLINE_FLAGS)

debug: fclean $(LIBFT) $(OBJS)
	@echo "Compiling $(NAME) project with debug flags"
	@$(CC) $(DEBUG_FLAGS) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(READLINE_FLAGS)

docker: fclean $(LIBFT) $(OBJS)
	@echo "Compiling $(NAME) project with debug flags for docker"
	@$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(READLINE_FLAGS)

# Compile source files into object files in the obj/ folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Create the obj/ directory if it doesn't exist
$(OBJ_DIR):
	@echo "Creating folders for object files"
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

# Build the libft library by calling its Makefile
$(LIBFT):
	@echo "Creating libft"
	@$(MAKE) -C $(LIBFT_DIR) all

# Clean object files from both fdf and libft
clean:
	@echo "Deleting $(NAME) objects"
	@rm -rf $(OBJ_DIR)
	@echo "Deleting libft objects"
	@$(MAKE) -C $(LIBFT_DIR) clean


# Full clean: also remove the executable and libft objects
fclean: clean
	@echo "Deleting $(NAME) executable"
	@$(RM) $(NAME)
	@echo "Deleting libft library"
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Norm rule
norm:
	@echo "Norminette for $(NAME):"
	@-norminette $(SRC_DIR) $(LIBFT_DIR) $(INC_DIR) || true

# PHONY prevents conflicts with files named like the targets
.PHONY: all clean fclean re
