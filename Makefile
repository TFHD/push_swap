NAME	:= 	push_swap

NAMEB	:= 	checker

DIR		:=	srcs/

DIRB	:=	srcs_bonus/

SRCS	:= 	push_swap.c \
			parsing.c \
			stack_function.c \
			do_stack_function.c \
			do_stack_function_2.c \
			get_min_max.c \
			fast_sort.c \
			sort.c \
			quick_sort.c \
			calculate_best_moves.c \
			bm_utils.c \
			parsing_utils.c

SRCSB	:= checker_bonus.c \
			push_swap_bonus.c \
			parsing_bonus.c \
			stack_function_bonus.c \
			do_stack_function_bonus.c \
			do_stack_function_2_bonus.c \
			get_min_max_bonus.c \
			fast_sort_bonus.c \
			sort_bonus.c \
			quick_sort_bonus.c \
			calculate_best_moves_bonus.c \
			bm_utils_bonus.c \
			parsing_utils_bonus.c

OBJSB	:=	$(patsubst %.c, $(DIRB)%.o, $(SRCSB))

OBJS	:=	$(patsubst %.c, $(DIR)%.o, $(SRCS))

LIBS	:= libft.a libftprintf.a

CC		:= cc

FLAGS 	:= 	-Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS} ${LIBS}
	${CC} -o ${NAME} ${OBJS} ${LIBS}

${LIBS}:
	make -C libft
	mv libft/libft.a ./
	mv libft/libftprintf.a ./

${DIR}%.o: ${DIR}%.c
	${CC} ${FLAGS} -o $@ -c $<

bonus: ${NAMEB}
	
${NAMEB}: ${OBJSB} ${LIBS}
	${CC} -o ${NAMEB} ${OBJSB} ${LIBS}

${DIRB}%.o: ${DIRB}%.c
	${CC} ${FLAGS} -o $@ -c $<

clean:
	rm -f ${OBJS} ${OBJSB}
	make -C libft clean
	make -C libft/ft_printf clean

fclean: clean
	rm -f ${NAME}
	rm -f ${LIBS}
	rm -f checker

re: fclean all

.PHONY: clean fclean re all
