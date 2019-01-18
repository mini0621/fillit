NAME = fillit

CC = gcc 

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I .

SRC = solve.c validate.c lst_tet.c t_tet.c fillit.c square.c ft_bzero.c \
	  ft_memalloc.c ft_closesqrt.c ft_memcpy.c ft_lstdel.c ft_memset.c ft_lstnew.c \
	  ft_putendl.c ft_lstpushback.c ft_strnew.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

RM = rm -f 

$(NAME): $(OBJ)
	$(CC) -o $@ $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
