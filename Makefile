
NAME		= fillit
CFLAGS	= -Wall -Werror -Wextra -I. -L libft/ -lft -c
FILES		= $(*.c)
OBJ			= $(FILES:%.c=%.o)

all: $(NAME)

# This won't run if the .o files don't exist or are not modified
$(NAME): $(OBJ)
	@gcc  $(OBJ)  libft/libft.a -I. -o $(NAME)

# This won't run if the source files don't exist or are not modified
$(OBJ): $(FILES)
	@gcc $(CFLAGS) $(FILES)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re