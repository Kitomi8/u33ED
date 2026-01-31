NAME = cube3D

CC = cc

FLAGS = -Wall -Wextra -Werror -I

MLX_PATH = ./mlx

MLX_LINK = -L$(MLX_PATH) -lmlx -lXnet -lX11 -lm

SRC =	command_hook.c\
		main.c\
		render_frame.c\
		close_game.c\
		crotate_player.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_PATH)
	$(CC) $(PBJ) $(MLX_LINK) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
	@make -C $(MLX_PATH) clean
	rm -rf $(OBJ)

ftclean: clean
		rm -rf $(NAME)

re: all

.PHONY: all clean fclean re