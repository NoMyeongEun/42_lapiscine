CC = cc # define variable for setting compiler
FLAGS= -Wall -Wextra -Werror # define variable for compile options about warning
NAME = libft.a # define variable for the target file
SRC = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c # specify the source files' directory and name
OBJ = $(SRC:.c=.o) # equals to "./srcs/ft_putchar.o ./srcs/ft_swap.o ..." - changes '.c' to '.o' in SRC variable
INC = -Iincludes/ # specify the path where the header file is
HEADER = includes/ft.h # specify the path and file name where the header file is

all : $(NAME) # equals to 'make' command. make the target file(=libft.a)

%.o : %.c $(HEADER) # specify how to make the object files. '$<' means the first string of the dependency file list. '$@' means the name of target file. '%.o' means the file that ends with '.o'.
	$(CC) $(FLAGS) $(INC) -c $< -o $@ 

$(NAME) : $(OBJ) # specify how to make the target file - archieving object files to "libft.a" file
	ar rc $(NAME) $(OBJ)

clean :  # delete the objects files all
	rm -f $(OBJ)

fclean : clean # delete not only the object files but also the target file
	rm -f $(NAME) 
	
re : fclean all # delete all files(objects files and target file and remake all the files.
