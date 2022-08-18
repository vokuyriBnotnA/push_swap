/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 06:50:03 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/20 09:14:19 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_main	rotate(t_stack_main a)
{
	a.stack_main = a.begin->next;
	a.begin = a.stack_main;
	return (a);
}

t_stack_main	ra(t_stack_main a, int message)
{
	if (message)
		write(1, "ra\n", 3);
	return (rotate(a));
}

t_stack_main	rb(t_stack_main b, int message)
{
	if (message)
		write(1, "rb\n", 3);
	return (rotate(b));
}

t_stack_all	rr(t_stack_all st, int message)
{
	if (message)
		write(1, "rr\n", 3);
	st.a = rotate(st.a);
	st.b = rotate(st.b);
	return (st);
}
