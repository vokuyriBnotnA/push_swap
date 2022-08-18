/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:47:28 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/20 09:14:29 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*return_pointer_next_num(t_stack_main lst, long num)
{
	int		i;
	int		st_count;
	long	dif;
	t_stack	*res;

	i = 0;
	dif = 2147483648;
	st_count = lst_count(lst);
	while (i <= st_count)
	{
		if ((long) lst.stack_main->index > num
			&& (long) lst.stack_main->index < dif)
		{
			dif = (long) lst.stack_main->index;
			res = lst.stack_main;
		}
		lst.stack_main = lst.stack_main->next;
		i++;
	}
	return (res);
}

static void	zero_index(t_stack_main lst)
{
	int	i;
	int	st_count;

	i = 0;
	st_count = lst_count(lst);
	while (i <= st_count)
	{
		lst.stack_main->index = 0;
		lst.stack_main = lst.stack_main->next;
		i++;
	}
}

void	sort_index(t_stack_main lst)
{
	int		i;
	int		st_count;
	long	num;

	i = 0;
	num = -2147483649;
	st_count = lst_count(lst);
	lst.stack_main = return_pointer_next_num(lst, num);
	lst.stack_main->num = i + 1;
	num = lst.stack_main->index;
	i++;
	while (i <= st_count)
	{
		lst.stack_main = return_pointer_next_num(lst, num);
		lst.stack_main->num = i + 1;
		num = lst.stack_main->index;
		i++;
	}
	zero_index(lst);
}
