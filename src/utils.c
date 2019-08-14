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

static void	ft_ps_stack_free(t_stack **st)
{
	t_stack	*next;

	while (*st)
	{
		next = (*st)->next;
		free(*st);
		*st = next;
	}
}

int			ft_ps_stacks_free(t_stacks **sts, int ret_val)
{
	if (*sts && (*sts)->a)
		ft_ps_stack_free(&(*sts)->a);
	if (*sts && (*sts)->b)
		ft_ps_stack_free(&(*sts)->b);
	if (*sts)
		free(*sts);
	return (ret_val);
}

void		ft_ps_put_error(t_stacks **sts, int ret_val)
{
	ft_putstr("Error\n");
	ft_ps_stacks_free(sts, ret_val);
	exit(ret_val);
}

int			ft_ps_st_set_tmp_cmds(t_stacks *sts, t_stack *tmp_b)
{
	sts->tmp_pl = ft_ps_get_node_place_i(sts->a, tmp_b->val);
	sts->tmp_b = ft_ps_node_iter_to_up(sts->len_b, tmp_b->i);
	sts->tmp_a = ft_ps_node_iter_to_up(sts->len_a, sts->tmp_pl);
	return (ft_ps_node_b_to_a_count(sts->tmp_a, sts->tmp_b, sts->tmp_pl));
}

void		ft_ps_st_copy_tmp_to_opt_cmds(t_stacks *sts)
{
	sts->opt_pl = sts->tmp_pl;
	sts->opt_b = sts->tmp_b;
	sts->opt_a = sts->tmp_a;
}
