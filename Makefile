NAME = fillit
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = normichno.c moding.c naris.c fillit.c check.c karta.c ./libft/libft.a
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME): $(LIBFT)
	@gcc $(SRCS) $(FLAGS) -o $(NAME)

g:
	@gcc -g $(SRCS) -o $(NAME)

clean:
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all

$(LIBFT):
	$(MAKE) -C ./libft all

git:
	git add .
	git commit -am "$(G)"
	git push

val: re
	valgrind --leak-check=full  ./fillit $(G)
