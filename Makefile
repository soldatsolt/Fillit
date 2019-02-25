NAME = fillit
MAKE = make
override G += 

all: $(NAME)

$(NAME):
	gcc fillit.c ./libft/libft.a -o $(NAME)

g:
	gcc -g fillit.c ./libft/libft.a

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