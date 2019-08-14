/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 19:51:56 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/19 14:08:58 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		ft_ps_set_index(t_stack *st)
{
	int i;

	i = 0;
	while (st)
	{
		st->i = i;
		i++;
		st = st->next;
	}
}

t_stack		*ft_ps_get_max_sort(t_stack *st)
{
	t_stack	*tmp;
	t_stack *first;
	t_stack *max;
	int		nodes;
	int		i;

	first = st;
	max = st;
	nodes = ft_ps_get_count_nodes(st);
	while (st)
	{
		tmp = st;
		i = 0;
		while (i < nodes)
		{
			if ((tmp->next == NULL ? first : tmp->next)->val < tmp->val)
				break ;
			st->sort++;
			i++;
			tmp = tmp->next == NULL ? first : tmp->next;
		}
		max = st->sort >= max->sort ? st : max;
		st = st->next;
	}
	return (max);
}

int			ft_ps_node_iter_to_up(int st_len, int node_i)
{
	if (st_len / 2 >= node_i)
		return (node_i);
	else
		return ((st_len - node_i) * -1);
}

int			ft_ps_get_node_place_i(t_stack *st, int node_val)
{
	t_stack *optim;
	int		last_min;

	optim = NULL;
	last_min = 0;
	while (st)
	{
		if ((last_min == 0) || (last_min < 0 && st->val - node_val < 0 &&
			st->val - node_val > last_min) ||
			(last_min > 0 && st->val - node_val < last_min))
		{
			last_min = st->val - node_val;
			optim = st;
		}
		if (st->next == NULL)
			break ;
		st = st->next;
	}
	if (optim == st && last_min < 0)
		return (-1);
	return (last_min < 0 ? optim->i + 1 : optim->i);
}

int			ft_ps_node_b_to_a_count(int a, int b, int place_b)
{
	if (a > 0 && b > 0 && place_b != -1)
		return (a > b ? a : b);
	if (a < 0 && b < 0 && place_b != -1)
		return (ft_abs(a) > ft_abs(b) ? ft_abs(a) : ft_abs(b));
	else
		return (ft_abs(a) + ft_abs(b));
}
