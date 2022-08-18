/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 21:10:19 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/20 09:12:50 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_input(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (((str[i] != '-'
					|| (str[i] == '-' && !is_digit(str[i + 1])))
				&& (str[i] < '0' || str[i] > '9')) && str[i] != ' ')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	check_repeat(t_stack_main stack)
{
	int				i;
	int				j;
	int				stack_count;
	t_stack_main	stack_2;

	i = 0;
	stack.stack_main = stack.begin;
	stack_count = lst_count(stack);
	while (i < stack_count)
	{
		j = i + 1;
		stack_2.stack_main = stack.stack_main->next;
		while (j <= stack_count)
		{
			if (stack.stack_main->index == stack_2.stack_main->index)
				return (0);
			stack_2.stack_main = stack_2.stack_main->next;
			j++;
		}
		stack.stack_main = stack.stack_main->next;
		i++;
	}
	return (1);
}

int	check_sort(t_stack_main lst)
{
	lst.stack_main = lst.begin;
	while (lst.stack_main != lst.begin->prev)
	{
		if (lst.stack_main->num > lst.stack_main->next->num)
			return (0);
		lst.stack_main = lst.stack_main->next;
	}
	return (1);
}
