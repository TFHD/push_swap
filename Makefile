NAME	:= 	push_swap

DIR		:=	srcs/

SRCS	:= 	push_swap.c parsing.c stack_function.c

OBJS	:=	$(patsubst %.c, $(DIR)%.o, $(SRCS))

LIB		:= libft.a

HEAD	:=	libft/libft.h includes/push_swap.h

CC		:= 	cc

FLAGS 	:= 	-Wall -Werror -Wextra -g

all: ${NAME}

${NAME}: ${OBJS} ${LIB}
	${CC} -o ${NAME} ${OBJS} ${LIB}

${LIB}:
	make -C libft
	mv libft/libft.a ./

%.o: %.c
	${CC} ${FLAGS} -o $@ -c $<

clean:
	rm -f ${OBJS}
	make -C libft clean

fclean: clean
	rm -f ${NAME}
	rm -f ${LIB}

re: fclean all

.PHONY: clean fclean re all
