/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 06:50:17 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/20 09:14:04 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_main	reverse_rotate(t_stack_main a)
{
	a.stack_main = a.begin->prev;
	a.begin = a.stack_main;
	return (a);
}

t_stack_main	rra(t_stack_main a, int message)
{
	if (message)
		write(1, "rra\n", 4);
	return (reverse_rotate(a));
}

t_stack_main	rrb(t_stack_main b, int message)
{
	if (message)
		write(1, "rrb\n", 4);
	return (reverse_rotate(b));
}

t_stack_all	rrr(t_stack_all st, int message)
{
	if (message)
		write(1, "rrr\n", 4);
	st.a = reverse_rotate(st.a);
	st.b = reverse_rotate(st.b);
	return (st);
}
