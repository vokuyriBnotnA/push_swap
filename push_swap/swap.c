/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 06:50:31 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/21 14:24:53 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_main	swap(t_stack_main a)
{
	int	num_1;
	int	num_2;

	a.stack_main = a.begin;
	num_1 = a.stack_main->num;
	a.stack_main = a.stack_main->next;
	num_2 = a.stack_main->num;
	a.stack_main->num = num_1;
	a.stack_main = a.begin;
	a.stack_main->num = num_2;
	return (a);
}

t_stack_main	sa(t_stack_main a, int message)
{
	if (message)
		write(1, "sa\n", 3);
	if (lst_count(a) > 1)
		a = swap(a);
	return (a);
}

t_stack_main	sb(t_stack_main b, int message)
{
	if (message)
		write(1, "sb\n", 3);
	if (lst_count(b) > 1)
		b = swap(b);
	return (b);
}

t_stack_all	ss(t_stack_all st, int message)
{
	if (message)
		write(1, "ss\n", 3);
	if (lst_count(st.a) > 1 && lst_count(st.b) > 1)
	{
		st.a = swap(st.a);
		st.b = swap(st.b);
	}
	return (st);
}
