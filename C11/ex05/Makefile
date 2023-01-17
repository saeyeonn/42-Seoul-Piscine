NAME = do-op

SRCS = ft_atoi.c do_op.c ft_putnbr.c ft_putstr.c operate.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(wildcard *.o)

fclean : clean
	rm -f $(NAME)

re : fclean all
