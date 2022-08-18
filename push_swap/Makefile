# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 19:01:58 by klemongr          #+#    #+#              #
#    Updated: 2022/01/21 17:27:11 by klemongr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_CHECK = checker

FLAGS = -Wall -Wextra -Werror

LIST =	add_to_stack.c		\
		checkers.c 			\
		greatest_sequence.c	\
		main.c				\
		module.c			\
		push_swap.c			\
		push_swap_3.c		\
		push.c				\
		reverse_rotate.c	\
		rotate.c			\
		sort_index.c		\
		stack_func.c		\
		step.c				\
		swap.c				\

LIST_CHECK = 	my_check.c		\
				add_to_stack.c	\
				checkers.c 		\
				module.c		\
				push.c			\
				reverse_rotate.c\
				rotate.c		\
				sort_index.c	\
				stack_func.c	\
				swap.c			\
				gnl.c

OBJSFD = temporary

OBJ = $(addprefix $(OBJSFD)/,$(LIST:.c=.o))

OBJ_CHECK = $(addprefix $(OBJSFD)/,$(LIST_CHECK:.c=.o))

all : $(NAME) $(NAME_CHECK)

FORCE:		;

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: %.c | $(OBJSFD)
	gcc -g $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	gcc -g $(OBJ) -o $@

$(NAME_CHECK) : $(OBJ_CHECK)
	gcc -g $(OBJ_CHECK) -o $@

clean :
	rm -f $(OBJ)
	rm -f $(OBJ_CHECK)

fclean : clean
	rm -f $(NAME_CHECK)

re : fclean all

.PHONY : all clean fclean re
