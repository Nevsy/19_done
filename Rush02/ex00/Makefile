CC		= cc
SRCS	= parsing.c \
ft_helper.c \
ft_parse_helper1.c \
ft_parse_helper2.c \
print_numbers.c \
print_numbers_helper.c \
ft_main_helper.c \
main.c
OBJS	= ${SRCS:.c=.o}

RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g
#CFLAGS	= -Wall -Wextra -Werror

NAME	= rush-02

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
