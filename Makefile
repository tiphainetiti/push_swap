#################################################
## COLORS
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
END = \033[0m

#################################################
## ARGUMENTS

NAME				= push_swap
CFLAGS				= -Wall -Werror -Wextra -g3
CC					= cc
LIBFT				= libft
bonus				= checker


#################################################
## SOURCES

SRC_FILES			= 	main \
						ft_stack_init \
						my_split \
						my_strjoin \
						parsing \
						parsing_utils \
						ft_error \
						ft_atol \
						ft_atoull \
						ft_atoll \
						com_swap \
						com_push \
						com_rotate \
						com_rev_rot \
						lst_utils1 \
						lst_utils2 \
						algo_utils \
						small_sort \
						ft_find_place \
						ft_cost \
						ft_cost_cases \
						ft_cost_apply \
						algo \


OBJ_FILES			= $(addsuffix .o, ${SRC_FILES})

SRC_BONUS			= checker \

OBJ_BONUS			= $(addsuffix .o, ${SRC_BONUS})

#################################################
## RULES

${NAME} : ${OBJ_FILES}
		@make --silent -C $(LIBFT)
		@cp $(LIBFT)/libft.a ${NAME}
		@${CC} ${CFLAGS} -o ${NAME} ${OBJ_FILES} -L $(LIBFT) -lft
		@echo "$(GREEN)Compilation terminée!$(END) "

${BONUS} : ${OBJ_BONUS}
		make -C $(LIBFT)
		${CC} ${CFLAGS} ${OBJ_FILES} -o ${NAME} -L $(LIBFT) -lft

all : ${NAME}

%.o : %.c
		@${CC} ${CFLAGS} -c $< -o $@

clean :
		@rm -f *.o
		@make clean --silent -C $(LIBFT)
		clear
		@echo "$(CYAN)C'est tout propre !$(END)"

fclean : clean
		@rm -f ${NAME}
		@make fclean --silent -C $(LIBFT)

re : fclean all

bonus : ${BONUS}

.PHONY : all clean fclean re