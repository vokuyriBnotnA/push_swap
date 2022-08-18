/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:32:45 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/21 13:44:17 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_all	push_swap_3(t_stack_all st)
{
	if (st.a.begin->num == 1)
	{
		st.a = ra(st.a, 1);
		st.a = sa(st.a, 1);
		st.a = rra(st.a, 1);
	}
	else if (st.a.begin->num == 2)
	{
		if (st.a.begin->next->num == 1)
			st.a = sa(st.a, 1);
		else
			st.a = rra(st.a, 1);
	}
	else if (st.a.begin->num == 3)
	{
		st.a = ra(st.a, 1);
		if (st.a.begin->num == 2)
			st.a = sa(st.a, 1);
	}
	return (st);
}
