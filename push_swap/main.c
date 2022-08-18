/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:29:48 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/21 14:30:20 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_all	st;

	if (argc < 2)
	{
		return (1);
	}
	st = init();
	st = add_to_stack(st, argv);
	if (!check_repeat(st.a))
		error_exit(st);
	sort_index(st.a);
	if (check_sort(st.a))
	{
		free_stack(st);
		exit(1);
	}
	if (st.a.begin->next->num + 1 == st.a.begin->num && lst_count(st.a) != 2)
		st.a = sa(st.a, 1);
	greatest_sequence(st.a);
	if (lst_count(st.a) == 2)
		st = push_swap_3(st);
	else
		st = push_swap(st);
	free_stack(st);
	return (0);
}
