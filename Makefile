RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
WHITE  = $(shell printf "\33[37m")
YELLOW = $(shell printf "\33[33m")
RESET  = $(shell printf "\33[0m")
BLUE = $(shell printf "\33[34m")
PURPLE = $(shell printf "\33[35m")
TITLE = $(shell printf "\33[32;40m")

NAME = push_swap
CHECKER = checker
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g -Iincludes
LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC_1 = $(wildcard srcs/*.c)

SRC_2 = $(wildcard srcs/*/*.c) \

SRC_CHECKER = $(wildcard bonus/*.c)

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}
OBJ_CHECKER = ${SRC_CHECKER:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	@make --silent -C $(LIBFTDIR)
	@${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}
	@echo "$(PURPLE)██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "
	@echo
	@echo "$(GREEN) Successfully compiled push_swap.$(RESET)"
	@echo
	@echo

all: ${NAME}

${CHECKER}: ${OBJ_CHECKER}
	@${CC} ${FLAGS} ${OBJ_CHECKER} -o ${CHECKER} ${INCLUDE}

bonus: ${CHECKER}

clean:
	@${RM} ${OBJ_1} ${OBJ_2} ${OBJ_CHECKER} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) --silent clean

fclean: clean
	@${RM} ${NAME} ${CHECKER}
	@cd $(LIBFTDIR) && $(MAKE) --silent fclean

re: clean all

.PHONY: all clean fclean re bonus
