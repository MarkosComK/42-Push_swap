NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g
LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC_1 = srcs/push_swap/push_swap.c \

SRC_2 =

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	@${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	@make --silent -C $(LIBFTDIR)
	@${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

all: ${NAME} ${BONUS}

clean:
	@${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	@${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus
