/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:09:41 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/19 13:57:14 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_ps_is_valid_int(int val_i, char *val_c)
{
	char	*cur_val;
	int		res;

	res = 0;
	cur_val = ft_itoa(val_i);
	if (ft_strcmp(cur_val, val_c) == 0)
		res = 1;
	if (cur_val)
		free(cur_val);
	return (res);
}

int	ft_ps_is_not_dupl(t_stack *st, int val)
{
	while (st)
	{
		if (st->val == val)
			return (0);
		st = st->next;
	}
	return (1);
}

int	ft_ps_is_sort_stacks(t_stacks *sts)
{
	t_stack	*st_a;
	int		last_val;

	if (sts->b != NULL)
		return (0);
	st_a = sts->a;
	last_val = st_a->val;
	while (st_a)
	{
		if (last_val > st_a->val)
			return (0);
		last_val = st_a->val;
		st_a = st_a->next;
	}
	return (1);
}
