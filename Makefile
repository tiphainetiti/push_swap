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
BUILD				= objs/
BONUS_EXEC			= checker


#################################################
## SOURCES

SRC_FILES_1			=	main \

SRC_FILES_2			= 	ft_stack_init \
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
						small_sort \
						ft_find_place \
						ft_cost \
						ft_cost_cases \
						ft_cost_apply \
						algorithm \
						algorithm_utils \


SRC_1			= 	$(addprefix srcs/, $(SRC_FILES_1))
SRC_2			= 	$(addprefix srcs/, $(SRC_FILES_2))


OBJ_FILES_1		= $(addprefix $(BUILD), $(addsuffix .o, $(SRC_FILES_1)))
OBJ_FILES_2		= $(addprefix $(BUILD), $(addsuffix .o, $(SRC_FILES_2)))


SRC_BONUS			= checker \
						checker_utils \


BONUS			= 	$(addprefix bonus/, $(SRC_BONUS))


OBJ_BONUS		= $(addprefix $(BUILD), $(addsuffix .o, $(SRC_BONUS)))

#################################################
## RULES

${NAME} : ${OBJ_FILES_1} ${OBJ_FILES_2}
		@make --silent -C $(LIBFT)
		@cp $(LIBFT)/libft.a ${NAME}
		@${CC} ${CFLAGS} -o ${NAME} ${OBJ_FILES_1} ${OBJ_FILES_2} -L $(LIBFT) -lft
		@echo "$(GREEN)Compilation terminée! 👍$(END) "

${BONUS_EXEC} : ${OBJ_BONUS} ${OBJ_FILES_2}
		@make --silent -C $(LIBFT)
		@cp $(LIBFT)/libft.a ${BONUS_EXEC}
		@${CC} ${CFLAGS} -o ${BONUS_EXEC} ${OBJ_BONUS} ${OBJ_FILES_2} -L $(LIBFT) -lft
		@echo "$(GREEN)Compilation de la version bonus terminée! 👍$(END) "

objs/%.o: srcs/%.c
	@mkdir -p ${BUILD}
	@${CC} ${CFLAGS} -c $< -o $@

objs/%.o: bonus/%.c
	@mkdir -p ${BUILD}
	@${CC} ${CFLAGS} -c $< -o $@

all : ${NAME}

%.o : %.c
		@${CC} ${CFLAGS} -c $< -o $@

clean :
		@rm -f ${BUILD}/*.o
		@rm -f bonus/*.o
		@rm -f bonus/libft.a
		@make clean --silent -C $(LIBFT)
		clear
		@echo "$(CYAN)All clean !$(END)"

fclean : clean
		@rm -f ${NAME}
		@rm -f ${BONUS_EXEC}
		@rm -rf ${BUILD}
		@make fclean --silent -C $(LIBFT)

re : fclean all

bonus : ${BONUS_EXEC}

.PHONY : all clean fclean re bonus
