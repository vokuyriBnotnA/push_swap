/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:45:18 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/20 10:17:52 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_all	init(void)
{
	t_stack_all	lst;

	lst.a.stack_main = (t_stack *) malloc(sizeof(t_stack));
	lst.b.stack_main = (t_stack *) malloc(sizeof(t_stack));
	if (!lst.a.stack_main || !lst.b.stack_main)
		return (lst);
	lst.a.stack_main->num = 0;
	lst.b.stack_main->num = 0;
	lst.a.stack_main->index = 0;
	lst.b.stack_main->index = 0;
	lst.a.stack_main->next = lst.a.stack_main;
	lst.a.stack_main->prev = lst.a.stack_main;
	lst.b.stack_main->next = lst.b.stack_main;
	lst.b.stack_main->prev = lst.b.stack_main;
	lst.a.begin = lst.a.stack_main;
	lst.b.begin = lst.b.stack_main;
	return (lst);
}

t_stack	*addelem(t_stack *lst, int num, int ind)
{
	t_stack	*temp;
	t_stack	*n;

	temp = (t_stack *) malloc(sizeof(t_stack));
	if (!temp)
		return (NULL);
	n = lst->next;
	lst->next = temp;
	if (ind == 0)
		temp->num = num;
	else
		temp->index = num;
	temp->next = n;
	temp->prev = lst;
	n->prev = temp;
	return (temp);
}

t_stack	*deleteelem(t_stack *lst)
{
	t_stack	*next;
	t_stack	*prev;

	prev = lst->prev;
	next = lst->next;
	prev->next = lst->next;
	next->prev = lst->prev;
	free(lst);
	return (prev);
}

void	free_stack(t_stack_all lst)
{
	int	i;
	int	st_count;

	i = 0;
	st_count = lst_count(lst.a);
	while (i <= st_count)
	{
		free(lst.a.stack_main);
		lst.a.stack_main = lst.a.stack_main->next;
		i++;
	}
	i = 0;
	st_count = lst_count(lst.b);
	while (i <= st_count)
	{
		free(lst.b.stack_main);
		lst.b.stack_main = lst.b.stack_main->next;
		i++;
	}
}
