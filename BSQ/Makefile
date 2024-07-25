CC		=	cc
SRCS	=	main.c \
			algo.c \
			draw_square.c \
			parsing.c \
			errors.c \
			ft_helper.c \
			parsing_stdin.c \
			parsing_helper.c \
			settings.c \
			settings_stdin.c

OBJS	= ${SRCS:.c=.o}

RM		= rm -f
#CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g
#CFLAGS	= -fsanitize=address -g
CFLAGS	= -Wall -Wextra -Werror

NAME	= bsq

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
	make clean
