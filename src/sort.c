/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:52:00 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/19 16:33:41 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_ps_st_a_norm(t_stacks *sts)
{
	int com;

	ft_ps_set_index(sts->a);
	sts->max_sort = ft_ps_get_max_sort(sts->a);
	sts->len_a = ft_ps_get_count_nodes(sts->a);
	com = sts->len_a - sts->max_sort->i - sts->max_sort->sort > 0 ?
		sts->len_a - (sts->len_a - sts->max_sort->i - sts->max_sort->sort) :
		ft_abs(sts->len_a - sts->max_sort->i - sts->max_sort->sort);
	com = ft_ps_node_iter_to_up(sts->len_a, com);
	ft_ps_cmd_apply_cnt(com > 0 ? "ra" : "rra", com, sts);
}

void	ft_ps_st_a_to_b(t_stacks *sts)
{
	t_stack *st_a;

	st_a = sts->a;
	while (st_a && st_a->i != sts->max_sort->i)
	{
		st_a = st_a->next;
		ft_ps_cmd_apply_cnt("pb", 1, sts);
	}
}

void	ft_ps_node_b_to_a(t_stacks *sts)
{
	sts->tmp_b = ft_abs(sts->opt_b);
	sts->tmp_a = ft_abs(sts->opt_a);
	while (((sts->opt_b > 0 && sts->opt_a > 0) || (sts->opt_b < 0 &&
			sts->opt_a < 0)) && sts->tmp_b && sts->tmp_a && sts->opt_pl != -1)
	{
		ft_ps_cmd_apply_cnt(sts->opt_b > 0 ? "rr" : "rrr", 1, sts);
		sts->tmp_b--;
		sts->tmp_a--;
	}
	ft_ps_cmd_apply_cnt(sts->opt_b > 0 ? "rb" : "rrb", sts->tmp_b, sts);
	if (sts->opt_pl != -1)
		ft_ps_cmd_apply_cnt(sts->opt_a > 0 ? "ra" : "rra", sts->tmp_a, sts);
	ft_ps_cmd_apply_cnt("pa", 1, sts);
	if (sts->opt_pl == -1)
		ft_ps_cmd_apply_cnt("ra", 1, sts);
}

void	ft_ps_st_b_to_a(t_stacks *sts)
{
	t_stack *tmp_b;
	int		min_cmds;
	int		cmds;

	while (sts->b)
	{
		tmp_b = sts->b;
		ft_ps_set_index(sts->a);
		ft_ps_set_index(sts->b);
		sts->len_a = ft_ps_get_count_nodes(sts->a);
		sts->len_b = ft_ps_get_count_nodes(sts->b);
		min_cmds = ft_ps_st_set_tmp_cmds(sts, tmp_b);
		ft_ps_st_copy_tmp_to_opt_cmds(sts);
		while (tmp_b)
		{
			cmds = ft_ps_st_set_tmp_cmds(sts, tmp_b);
			if (min_cmds > cmds)
			{
				min_cmds = cmds;
				ft_ps_st_copy_tmp_to_opt_cmds(sts);
			}
			tmp_b = tmp_b->next;
		}
		ft_ps_node_b_to_a(sts);
	}
}

void	ft_ps_st_a_min_to_top(t_stacks *sts)
{
	t_stack	*tmp_a;
	t_stack	*min_node;
	int		iter_to_up;

	tmp_a = sts->a;
	min_node = tmp_a;
	while (tmp_a)
	{
		min_node = tmp_a->val < min_node->val ? tmp_a : min_node;
		tmp_a = tmp_a->next;
	}
	sts->len_a = ft_ps_get_count_nodes(sts->a);
	ft_ps_set_index(sts->a);
	iter_to_up = ft_ps_node_iter_to_up(sts->len_a, min_node->i);
	ft_ps_cmd_apply_cnt(iter_to_up > 0 ? "ra" : "rra", iter_to_up, sts);
}
