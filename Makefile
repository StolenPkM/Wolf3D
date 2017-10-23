NAME = wolf3d

SRC_NAME = main.c draw.c raycast.c key_hook.c init.c move.c

SRC_DIR = ./src/

INCL_DIR = src

OBJ_DIR = ./obj/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CFLAGS = -Wall -Wextra -Werror -g3  

IFLAGS = -I./libft/ -I./minilibx_macos -I./$(INCL_DIR)

LFLAGS =  -L./libft -lft -framework OpenGL -framework AppKit -L./minilibx_macos -lmlx -lm

all : $(NAME)

.PHONY : all clean

$(NAME) : $(OBJ)
	make -C ./libft/
	make -C ./minilibx_macos/
	gcc $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) -c $(IFLAGS) $^ -o $@

norme :
	norminette $(SRC)
	norminette $(INCL_DIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	make clean -C libft/
	make clean -C minilibx_macos/

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re:fclean all
