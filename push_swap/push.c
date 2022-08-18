/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 06:50:43 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/20 09:13:51 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_all	pb(t_stack_all st, int message)
{
	int	value;

	if (message)
		write(1, "pb\n", 3);
	if (st.a.begin->num != 0)
	{
		value = st.a.begin->num;
		if (lst_count(st.a) == 0)
			st.a.begin->num = 0;
		else
		{
			st.a.stack_main = st.a.begin;
			st.a.begin = st.a.stack_main->next;
			st.a.stack_main = deleteelem(st.a.stack_main);
		}
		if (lst_count(st.b) == 0 && st.b.begin->num == 0)
			st.b.begin->num = value;
		else
		{
			st.b.stack_main = st.b.begin->prev;
			st.b.stack_main = addelem(st.b.stack_main, value, 0);
			st.b.begin = st.b.stack_main;
		}
	}
	return (st);
}

t_stack_all	pa(t_stack_all st, int message)
{
	int	value;

	if (message)
		write(1, "pa\n", 3);
	if (st.b.begin->num != 0)
	{
		value = st.b.begin->num;
		if (lst_count(st.b) == 0)
			st.b.begin->num = 0;
		else
		{
			st.b.stack_main = st.b.begin;
			st.b.begin = st.b.stack_main->next;
			st.b.stack_main = deleteelem(st.b.stack_main);
		}
		if (lst_count(st.a) == 0 && st.a.begin->num == 0)
			st.a.begin->num = value;
		else
		{
			st.a.stack_main = st.a.begin->prev;
			st.a.stack_main = addelem(st.a.stack_main, value, 0);
			st.a.begin = st.a.stack_main;
		}
	}
	return (st);
}
