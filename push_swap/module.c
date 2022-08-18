/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:52:59 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/20 09:29:18 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	module(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	error_exit(t_stack_all st)
{
	free_stack(st);
	write(2, "Error\n", 6);
	exit(1);
}
