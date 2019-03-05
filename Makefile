
NAME		= fillit
CFLAGS	= -Wall -Werror -Wextra -I. -c
FILES	= *.c
OBJ		= $(FILES:%.c=%.o)
LIB 	= libft/libft.a	
all: $(NAME)
	
$(NAME): $(OBJ)
	@gcc $(OBJ) $(LIB) -o $(NAME)

$(OBJ): $(FILES)
	@gcc $(CFLAGS)  $(FILES) 
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re