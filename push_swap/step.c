/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:29:31 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/21 14:28:13 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_steps(int step_a, int step_b)
{
	if ((step_a <= 0 && step_b <= 0) || (step_a >= 0 && step_b >= 0))
	{
		if (module(step_a) > module(step_b))
			return (module(step_a));
		else
			return (module(step_b));
	}
	else
	{
		return (module(step_a) + module(step_b));
	}
}

static int	max_value(t_stack_main a)
{
	int	res;

	res = 0;
	a.stack_main = a.begin->next;
	while (a.stack_main != a.begin)
	{
		if (a.stack_main->num > res)
			res = a.stack_main->num;
		a.stack_main = a.stack_main->next;
	}
	return (res);
}

int	step_calc(t_stack_main a, t_stack_main b)
{
	int	i;
	int	count_a;
	int	max;

	i = 0;
	count_a = lst_count(a);
	while (i <= count_a)
	{
		max = max_value(a);
		if ((b.stack_main->num > a.stack_main->prev->num
				&& b.stack_main->num < a.stack_main->num)
			|| (b.stack_main->num > max && a.stack_main->num == 1))
		{
			if (i == 0)
				return (i);
			if ((lst_count(a) + 1) / i > 2)
				return (i);
			else
				return ((lst_count(a) - i + 1) * -1);
		}
		a.stack_main = a.stack_main->next;
		i++;
	}
	return (0);
}

t_steps	step_res(t_stack_all st, int count)
{
	t_steps	res;
	int		i;
	int		minimum;

	i = 0;
	while (i < count)
	{
		st.b.stack_main = st.b.stack_main->prev;
		i++;
	}
	i = -count;
	minimum = 2147483647;
	while (i <= count)
	{
		if (add_steps(step_calc(st.a, st.b), i) < minimum)
		{
			res.step_a = step_calc(st.a, st.b);
			res.step_b = i;
			minimum = add_steps(step_calc(st.a, st.b), i);
		}
		st.b.stack_main = st.b.stack_main->next;
		i++;
	}
	return (res);
}

t_stack_all	step_2(t_stack_all st, t_steps s)
{
	while (s.step_a < 0)
	{
		st.a = rra(st.a, 1);
		s.step_a++;
	}
	while (s.step_a > 0)
	{
		st.a = ra(st.a, 1);
		s.step_a--;
	}
	while (s.step_b < 0)
	{
		st.b = rrb(st.b, 1);
		s.step_b++;
	}
	while (s.step_b > 0)
	{
		st.b = rb(st.b, 1);
		s.step_b--;
	}
	return (st);
}
