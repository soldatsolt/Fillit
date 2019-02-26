NAME = fillit
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc fillit.c check.c ./libft/libft.a -o $(NAME)

g:
	gcc -g fillit.c check.c ./libft/libft.a

clean:
	rm -f $(NAME) 

fclean: clean
	rm -f a.out 

re: clean all

lib:
	$(MAKE) -C ./libft re
	$(MAKE) -C ./libft clean

git:
	git add .
	git commit -am "$(G)"
	git push