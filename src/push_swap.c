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

static void	sort_three(t_stacks *sts)
{
	if (sts->a->val > sts->a->next->val &&
		sts->a->val < sts->a->next->next->val)
		cmd_apply_cnt("sa", 1, sts);
	else if (sts->a->val > sts->a->next->next->val)
		cmd_apply_cnt("ra", 1, sts);
}

static void	sort_five(t_stacks *sts)
{
	if (sts->max_sort->sort < 3)
	{
		cmd_apply_cnt("pb", 2, sts);
		sort_three(sts);
	}
	else
		st_a_to_b(sts);
	st_b_to_a(sts);
	st_a_min_to_top(sts);
}

static void	sort_other(t_stacks *sts)
{
	st_a_to_b(sts);
	st_b_to_a(sts);
	st_a_min_to_top(sts);
}

int			main(int ac, char **av)
{
	t_stacks *sts;

	sts = create_stacks(ac, av);
	if (sts->a == NULL)
		exit(stacks_free(&sts, 0));
	sts->cmd_print = 1;
	sts->len_a = get_count_nodes(sts->a);
	st_a_norm(sts);
	if (sts->len_a == 3)
		sort_three(sts);
	else if (sts->len_a == 5)
		sort_five(sts);
	else
		sort_other(sts);
	return (stacks_free(&sts, 0));
}
