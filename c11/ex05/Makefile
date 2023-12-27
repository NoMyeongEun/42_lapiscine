CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = do-op

SRC = ./srcs/main.c ./srcs/number.c ./srcs/operator.c ./srcs/calculate.c
OBJ = ./srcs/main.o ./srcs/number.o ./srcs/operator.o ./srcs/calculate.o
INC = -Iinclude/
HEADER = include/ft.h

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
