##
## EPITECH PROJECT, 2017
## LemiPC
## File description:
## Makeile for LemiPC
##

CC	= gcc -o2

RM	= rm -f

CFLAGS = -I./include
CFLAGS += -W -Wall -Wextra -Werror
#LDFLAGS =

SRCS	= main.c		\
	  map.c			\
	  map2.c		\
	  components.c		\
	  player.c		\
	  player_ai.c		\
	  player_ai2.c		\
	  player_control.c	\
	  check_diag.c		\
	  check_side.c		\
	  utils.c		\

OBJS    = $(addprefix src/, $(SRCS:.c=.o))

NAME	= lemipc

SRCS_TEST	= #SRC_TEST#

OBJS_TEST	= $(addprefix tests/, $(SRCS_TEST))

NAME_TEST	= tests_bin

ifeq    ($(DEBUG),yes)
        CC += -g3
endif

$(NAME): $(OBJS)
	 @$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	 @printf "\n-------------------\n"
	 @printf "\n\033[32m[OK]\033[0m Binary : \033[36m$(NAME)\033[0m\n"
	 @printf "\n-------------------\n"

%.o :    %.c
	 @printf "\033[32m[OK]\033[0m $<\n";
	 @$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

tests_run: $(OBJS_TEST)
	@$(CC) $(OBJS_TEST) -o $(NAME_TEST) $(LDFLAGS) -lcriterion -coverage
	@./$(NAME_TEST)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all tests_run clean fclean re
