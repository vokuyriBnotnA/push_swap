/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:42:28 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/21 17:35:13 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

static t_stack_all	push_swap_work(t_stack_all st, char *str)
{
	if (ft_strcmp(str, "sa\n"))
		st.a = sa(st.a, 0);
	else if (ft_strcmp(str, "sb\n"))
		st.b = sb(st.b, 0);
	else if (ft_strcmp(str, "ss\n"))
		st = ss(st, 0);
	else if (ft_strcmp(str, "pa\n"))
		st = pa(st, 0);
	else if (ft_strcmp(str, "pb\n"))
		st = pb(st, 0);
	else if (ft_strcmp(str, "ra\n"))
		st.a = ra(st.a, 0);
	else if (ft_strcmp(str, "rb\n"))
		st.b = rb(st.b, 0);
	else if (ft_strcmp(str, "rr\n"))
		st = rr(st, 0);
	else if (ft_strcmp(str, "rra\n"))
		st.a = rra(st.a, 0);
	else if (ft_strcmp(str, "rrb\n"))
		st.b = rrb(st.b, 0);
	else if (ft_strcmp(str, "rrr\n"))
		st = rrr(st, 0);
	else
		error_exit(st);
	return (st);
}

static t_stack_all	reading(t_stack_all st, char *str)
{
	str = get_next_line(0);
	while (str)
	{
		st = push_swap_work(st, str);
		free(str);
		str = get_next_line(0);
	}
	return (st);
}

int	main(int argc, char **argv)
{
	t_stack_all	st;
	char		*str;

	if (argc < 2)
		return (1);
	st = init();
	st = add_to_stack(st, argv);
	if (!check_repeat(st.a))
		error_exit(st);
	sort_index(st.a);
	st = reading(st, str);
	if (check_sort(st.a) && st.b.begin->num == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(st);
	return (0);
}
