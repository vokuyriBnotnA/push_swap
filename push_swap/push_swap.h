/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klemongr <klemongr@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:50:46 by klemongr          #+#    #+#             */
/*   Updated: 2022/01/21 17:37:54 by klemongr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_push
{
	int				num;
	int				index;
	struct s_push	*next;
	struct s_push	*prev;
}	t_stack;

typedef struct s_push_main
{
	t_stack	*stack_main;
	t_stack	*begin;
}	t_stack_main;

typedef struct s_all_stack
{
	t_stack_main	a;
	t_stack_main	b;
}	t_stack_all;

typedef struct s_step
{
	int	step_a;
	int	step_b;
}	t_steps;

t_stack_main	ra(t_stack_main a, int message);
t_stack_main	rb(t_stack_main b, int message);
t_stack_all		rr(t_stack_all st, int message);
t_stack_main	rra(t_stack_main a, int message);
t_stack_main	rrb(t_stack_main b, int message);
t_stack_all		rrr(t_stack_all st, int message);
t_stack_main	sa(t_stack_main a, int message);
t_stack_main	sb(t_stack_main b, int message);
t_stack_all		ss(t_stack_all st, int message);
t_stack_all		pa(t_stack_all st, int message);
t_stack_all		pb(t_stack_all st, int message);
t_stack_all		add_to_stack(t_stack_all st, char **argv);
t_stack_all		push_swap(t_stack_all st);
t_stack_all		push_swap_3(t_stack_all st);
t_steps			step_res(t_stack_all st, int count);
t_stack_all		step_2(t_stack_all st, t_steps s);
t_stack_all		init(void);
t_stack			*addelem(t_stack *lst, int num, int ind);
t_stack			*deleteelem(t_stack *lst);
void			free_stack(t_stack_all lst);
void			error_exit(t_stack_all st);
void			sort_index(t_stack_main lst);
void			greatest_sequence(t_stack_main lst);
int				step_calc(t_stack_main a, t_stack_main b);
int				lst_count(t_stack_main lst);
int				check_input(char *str);
int				check_repeat(t_stack_main stack);
int				check_sort(t_stack_main lst);
int				module(int num);
char			*get_next_line(int fd);

#endif