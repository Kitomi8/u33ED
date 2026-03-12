NAME = cub3D

LIBFT = libft/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = ./minilibx-linux
MLX_NAME = mlx
MLX_LIB = $(MLX_PATH)/lib$(MLX_NAME).a
MLX_INC = -I$(MLX_PATH)
MLX_LINK = -L$(MLX_PATH) -l$(MLX_NAME) -lXext -lX11 -lm -lbsd

SRC =	main.c \
		init_game.c \
		parsing/check_arg.c \
		utils/utils.c \
		raycasting/render_frame.c \
		raycasting/raycasting.c \
		raycasting/render_minimap.c \
		command_hook/close_game.c \
		command_hook/command_hook.c \
		raycasting/rotate_player.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(LIBFT):
	make -C ./libft

$(MLX_LIB):
	make -C $(MLX_PATH)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(MLX_LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C ./libft
	make clean -C $(MLX_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re