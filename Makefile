NAME = so_long

MLX = minilibx-linux/libmlx-Linux.a
MLX_DIR = minilibx-linux/

UTILS = utils/utils.a
UTILS_DIR = utils/

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
FCK_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -Lutils

SRC = so_long.c input_handler.c map_handler.c error_checks.c \
	path_finding.c so_long_utils.c graphic.c movement.c \
	rng.c movement_2.c graphic_2.c

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git ./minilibx-linux
	make -C ./minilibx-linux

all: $(NAME)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(UTILS):
	@$(MAKE) -C $(UTILS_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(PRINTF) $(UTILS)
	@$(CC) $(SRC) $(FCK_FLAGS) $(UTILS) -g -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re

