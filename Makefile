NAME = libftprintf.a

CC = gcc

CFLAG = -Wall -Wextra -Werror

INCLUDES = ./include/ft_printf.h

SRC = \
	source/ft_printf.c \
	source/ft_print_adress.c \
	source/ft_printf_hex.c \
	source/ft_printstr.c \
	source/ft_putnbr.c 

OBJS = $(SRC:.c=.o)

.c.o :
	${CC} -I ./include ${CFLAGS} -c $< -o ${<:.c=.o}

all :	${NAME}

$(NAME):	${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
	rm -f ${OBJS} 

fclean :	clean
	rm -f ${NAME}

re :	fclean all

.PHONY :	all clean fclean re bonus rebonus