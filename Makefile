##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## setting_up
##

NAME	=	103cipher

SRCS =	103cipher.c	\
		cipher.c \

CFLAGS = -lm -g3

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf *.o
	rm -rf *.a 

fclean: clean
	rm -rf $(NAME)
