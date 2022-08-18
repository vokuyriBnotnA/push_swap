/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:56 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/21 14:52:20 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_count(t_stack_main lst)
{
	int	i;

	i = 0;
	lst.stack_main = lst.begin->next;
	while (lst.stack_main != lst.begin)
	{
		lst.stack_main = lst.stack_main->next;
		i++;
	}
	return (i);
}

static int	str_to_int(char *str)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n *= (unsigned) 10;
			n += (unsigned) str[i] - '0';
		}
		if ((n > 2147483648 && str[0] == '-')
			|| (n > 2147483647 && str[0] != '-'))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	if (str[0] == '-')
		return (-n);
	return (n);
}

static int	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

t_stack_all	add_to_stack(t_stack_all st, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (!check_input(argv[i]))
			error_exit(st);
		if (is_space(argv[i]))
		{
			st.a.stack_main = addelem(st.a.stack_main, str_to_int(argv[i]), 1);
			while (argv[i][j++])
				if (argv[i][j] == ' ' && argv[i][j + 1])
					st.a.stack_main = addelem(st.a.stack_main,
							str_to_int(&argv[i][j + 1]), 1);
		}
		else
			st.a.stack_main = addelem(st.a.stack_main, str_to_int(argv[i]), 1);
		i++;
	}
	st.a.stack_main = st.a.begin;
	st.a.begin = st.a.stack_main->next;
	st.a.stack_main = deleteelem(st.a.stack_main);
	return (st);
}
