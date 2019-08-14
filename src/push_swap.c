/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:15:03 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/21 17:57:37 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_ps_sort_three(t_stacks *sts)
{
	if (sts->a->val > sts->a->next->val &&
		sts->a->val < sts->a->next->next->val)
		ft_ps_cmd_apply_cnt("sa", 1, sts);
	else if (sts->a->val > sts->a->next->next->val)
		ft_ps_cmd_apply_cnt("ra", 1, sts);
}

static void	ft_ps_sort_five(t_stacks *sts)
{
	if (sts->max_sort->sort < 3)
	{
		ft_ps_cmd_apply_cnt("pb", 2, sts);
		ft_ps_sort_three(sts);
	}
	else
		ft_ps_st_a_to_b(sts);
	ft_ps_st_b_to_a(sts);
	ft_ps_st_a_min_to_top(sts);
}

static void	ft_ps_sort_other(t_stacks *sts)
{
	ft_ps_st_a_to_b(sts);
	ft_ps_st_b_to_a(sts);
	ft_ps_st_a_min_to_top(sts);
}

int			main(int ac, char **av)
{
	t_stacks *sts;

	sts = ft_ps_create_stacks(ac, av);
	if (sts->a == NULL)
		exit(ft_ps_stacks_free(&sts, 0));
	sts->cmd_print = 1;
	sts->len_a = ft_ps_get_count_nodes(sts->a);
	ft_ps_st_a_norm(sts);
	if (sts->len_a == 3)
		ft_ps_sort_three(sts);
	else if (sts->len_a == 5)
		ft_ps_sort_five(sts);
	else
		ft_ps_sort_other(sts);
	return (ft_ps_stacks_free(&sts, 0));
}
