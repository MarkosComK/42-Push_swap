SRC_COMMON =

SRC_SORTER =	./src/sorter/main.c \

SRC_CHECKER =

OBJS_COMMON	= ${SRC_COMMON:.c=.o}
OBJS_SORTER		= ${SRC_SORTER:.c=.o}
OBJS_CHECKER	= ${SRC_CHECKER:.c=.o}

INCLUDE = ./src/include

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_CHECKER = checker

CC = gcc
RM = rm -f

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -I$(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS_COMMON) $(OBJS_SORTER)
			${CC} $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(OBJS_COMMON) $(OBJS_SORTER)

$(NAME_CHECKER): $(OBJS_COMMON) $(OBJS_CHECKER)
			${CC} $(CFLAGS) -I$(INCLUDE) -o $(NAME_CHECKER) $(OBJS_COMMON) $(OBJS_CHECKER)

clean:
			${RM} ${OBJS_COMMON} ${OBJS_SORTER} ${OBJS_CHECKER}

fclean: clean
			${RM} ${NAME} ${NAME_CHECKER}

re: fclean all

bonus: checker

.PHONY:		checker bonus all clean fclean re
