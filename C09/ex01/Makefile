SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC =	gcc

CFLAGS = -Wall -Wextra -Werror

INCS = includes

LIBC = ar rc 

RM = rm -f

%.o : %.c
				${CC} ${CFLAGS} -c $^ -o $@ -I ${INCS}

${NAME} :		${OBJS}
				${LIBC} ${NAME} ${OBJS}

all :			${NAME}

clean :
				${RM} ${OBJS}

fclean :		clean
				${RM} ${NAME}

re :			fclean all

.PHONY : all clean fclean re
