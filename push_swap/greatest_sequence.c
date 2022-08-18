/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greatest_sequence.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:27:09 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/21 13:23:50 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*next_elem(t_stack *st, t_stack *end)
{
	int		i;
	int		diff;
	t_stack	*res;
	t_stack	*num;

	i = 0;
	num = st;
	diff = 2147483647;
	while (st != end)
	{
		st = st->next;
		if (st->num >= num->num && st->num + i + num->num < diff)
		{
			diff = st->num + i + num->num;
			res = st;
		}
		i++;
	}
	if (diff == 2147483647)
		return (NULL);
	return (res);
}

void	greatest_sequence(t_stack_main lst)
{
	int		i;
	int		st_count;
	t_stack	*end;
	t_stack	*current;

	i = 2;
	st_count = lst_count(lst);
	while (lst.stack_main->num != 1)
		lst.stack_main = lst.stack_main->next;
	end = lst.stack_main->prev;
	lst.stack_main->index = 1;
	while (next_elem(lst.stack_main, end))
	{
		current = lst.stack_main;
		lst.stack_main = next_elem(lst.stack_main, end);
		lst.stack_main->index = i;
		i++;
	}
}
