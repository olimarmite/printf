CC=cc
CFLAGS= #-Wall -Wextra -Werror
LIBFT_DIR=libft
LIBFT_LIB= ${LIBFT_DIR}/libft.a
SRCS=ft_printf.c
NAME=libftprintf.a
OBJS= ${SRCS:.c=.o}
TEST_SRC=main.c
HEADERS=ft_printf.h ${LIBFT_DIR}/libft.h

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFT_DIR} all bonus
	cp ${LIBFT_LIB} ${NAME}
	ar -rc ${NAME} ${OBJS}

.c.o:
	${CC} -c ${CFLAGS} ${HEADERS} $<

clean:
	${MAKE} -C ${LIBFT_DIR} fclean
	${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	${RM} ${NAME}
	${RM} a.out

re: fclean all

test: all
	${CC} ${CFLAGS} ${NAME} ${TEST_SRC} ${OBJS} ${HEADERS}

.PHONY: all bonus clean fclean re test
