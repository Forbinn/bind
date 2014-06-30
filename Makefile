##
## Makefile
##
## Made by vincent leroy
## Login   <leroy_v@epitech.eu>
##
## Started on  Mar jui 24 20:51:09 2014 vincent leroy
## Last update Lun jui 30 20:55:21 2014 vincent leroy
##

SRC			= main.c \

CFLAGS		= -Wall -Wextra

LDFLAGS		=

NAME		= bind
NAME_DEBUG	= $(NAME).debug

OBJ			= $(SRC:.c=.o)
OBJ_DEBUG	= $(SRC:.c=.debug.o)

RM			= rm -f

CC			= gcc

MAKE		= make -C

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_DEBUG) *.swp *~ *#

fclean: clean
	$(RM) $(NAME) $(NAME_DEBUG)

re: fclean all

debug: CFLAGS += -ggdb3
debug: $(OBJ_DEBUG)
	$(CC) $(OBJ_DEBUG) $(LDFLAGS) -o $(NAME_DEBUG)

%.debug.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re debug
