/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 00:12:37 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/21 14:03:44 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_all	step(t_stack_all st)
{
	t_steps	s;

	st.a.stack_main = st.a.begin;
	st.b.stack_main = st.b.begin;
	s = step_res(st, module(step_calc(st.a, st.b)));
	while (s.step_a < 0 && s.step_b < 0)
	{
		st = rrr(st, 1);
		s.step_a++;
		s.step_b++;
	}
	while (s.step_a > 0 && s.step_b > 0)
	{
		st = rr(st, 1);
		s.step_a--;
		s.step_b--;
	}
	st = step_2(st, s);
	return (st);
}

int	check_for_push_b(t_stack_main a)
{
	a.stack_main = a.begin;
	while (a.stack_main != a.begin->prev)
	{
		if (a.stack_main->index == 0)
			return (1);
		a.stack_main = a.stack_main->next;
	}
	if (a.stack_main->index == 0)
		return (1);
	return (0);
}

static t_stack_all	push_b(t_stack_all st)
{
	int				i;
	int				st_count;

	i = 0;
	st_count = lst_count(st.a);
	st.a.stack_main = st.a.begin;
	while (i <= st_count && check_for_push_b(st.a))
	{
		st.a.stack_main = st.a.begin;
		if (st.a.stack_main->index == 0)
			st = pb(st, 1);
		else
			st.a = ra(st.a, 1);
		i++;
	}
	return (st);
}

static t_stack_all	push_end(t_stack_all st)
{
	int	i;

	i = 0;
	st.a.stack_main = st.a.begin;
	while (st.a.stack_main->num != 1)
	{
		st.a.stack_main = st.a.stack_main->next;
		i++;
	}
	if (i == 0)
		return (st);
	if ((lst_count(st.a) + 2) / i > 2)
		while (st.a.begin->num != 1)
			st.a = ra(st.a, 1);
	else
		while (st.a.begin->num != 1)
			st.a = rra(st.a, 1);
	return (st);
}

t_stack_all	push_swap(t_stack_all st)
{
	int	i;
	int	st_count;

	st = push_b(st);
	while (lst_count(st.b) > 0)
	{
		st = step(st);
		st = pa(st, 1);
	}
	if (st.b.begin->num != 0)
	{
		st = step(st);
		st = pa(st, 1);
	}
	st = push_end(st);
	return (st);
}
