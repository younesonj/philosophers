NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
SRCS = main.c parse.c init.c utils.c routine.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re 
