NAME = cube3D
CC = cc
FLAGS = -Wall -Wextra -Werror -g
MLX_PATH = ./minilibx-linux
MLX_NAME = mlx
MLX_LIB = $(MLX_PATH)/lib$(MLX_NAME).a
MLX_INC = -I$(MLX_PATH)
MLX_LINK = -L$(MLX_PATH) -l$(MLX_NAME) -lXext -lX11 -lm -lbsd

SRC = main.c init_game.c render_frame.c command_hook.c rotate_player.c close_game.c
OBJ = $(SRC:.c=.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_PATH)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LINK) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(MLX_INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re