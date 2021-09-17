/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:13:49 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/19 18:39:37 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	stack_free(t_stack **st)
{
	t_stack	*next;

	while (*st)
	{
		next = (*st)->next;
		free(*st);
		*st = next;
	}
}

int			stacks_free(t_stacks **sts, int ret_val)
{
	if (*sts && (*sts)->a)
		stack_free(&(*sts)->a);
	if (*sts && (*sts)->b)
		stack_free(&(*sts)->b);
	if (*sts)
		free(*sts);
	return (ret_val);
}

void		put_error(t_stacks **sts, int ret_val)
{
	ft_putstr("Error\n");
	stacks_free(sts, ret_val);
	exit(ret_val);
}

int			st_set_tmp_cmds(t_stacks *sts, t_stack *tmp_b)
{
	sts->tmp_pl = get_node_place_i(sts->a, tmp_b->val);
	sts->tmp_b = node_iter_to_up(sts->len_b, tmp_b->i);
	sts->tmp_a = node_iter_to_up(sts->len_a, sts->tmp_pl);
	return (node_b_to_a_count(sts->tmp_a, sts->tmp_b, sts->tmp_pl));
}

void		st_copy_tmp_to_opt_cmds(t_stacks *sts)
{
	sts->opt_pl = sts->tmp_pl;
	sts->opt_b = sts->tmp_b;
	sts->opt_a = sts->tmp_a;
}
