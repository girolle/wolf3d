NAME	= wolf3d

SRC		= sources/main.c \
		  sources/error.c \
		  sources/draw.c \
		  sources/init.c \
		  sources/loop.c \
		  sources/ray.c \
		  sources/read.c \
		  sources/key.c \
		  sources/move.c \
		  sources/map.c

OBJ		= $(patsubst sources/%.c,objects/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror -L libft/ -lft -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Wolf3d"

objects/%.o: sources/%.c
	mkdir -p objects
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf objects/
	make -C libft/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Wolf3d"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Wold3d"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all
