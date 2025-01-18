include srcs.mk

NAME = minishell

SRC_DIR = src
OUT_DIR = out
INC_DIR = includes

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

.DEFAULT_GOAL = all
       
OBJS = $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)/inc
READLINE_FLAGS = -lreadline -ltermcap

all: $(NAME)

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

$(LIBFT):
	@echo "Creating libft"
	@make -C $(LIBFT_DIR)

$(NAME): $(OUT_DIR) $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME) project"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

debug: fclean $(OUT_DIR) $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME) project with debug flags"
	@$(CC) -g -fsanitize=address $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

docker: fclean $(OUT_DIR) $(OBJS) $(LIBFT)
	@echo "Compiling $(NAME) project with debug flags for docker"
	@$(CC) -g $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

$(OUT_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Deleting $(NAME) objects"
	@rm -rf $(OUT_DIR)
	@echo "Deleting libft objects"
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Deleting $(NAME) executable"
	@rm -f $(NAME)
	@echo "Deleting libft library"
	@make -C $(LIBFT_DIR) fclean

norm:
	@echo "Norminette for $(NAME):"
	@-norminette $(SRC_DIR) $(LIBFT_DIR) $(INC_DIR) || true

bonus: all

re: fclean all

.PHONY: all clean fclean re norm debug docker bonus
