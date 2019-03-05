
NAME		= fillit
CFLAGS	= -Wall -Werror -Wextra -I. -L libft/ -lft -c
FILES		= *.c
OBJ			= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(FILES)
	gcc $(CFLAGS)  $(FILES)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re