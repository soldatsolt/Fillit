NAME = fillit
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = normichno.c moding.c naris.c fillit.c check.c karta.c ./libft/libft.a
all: $(NAME)

$(NAME):
	gcc $(SRCS) -o $(NAME)

g:
	gcc -g $(SRCS)

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

val: re
	valgrind --leak-check=full  ./fillit $(G)
