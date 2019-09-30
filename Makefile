

SRC = ./src/*.c
HEADER = ./includes/
NAME = ft_printf


all : $(NAME)

$(NAME):
	gcc  -I $(HEADER) $(SRC)

clean :
	rm $(NAME)

