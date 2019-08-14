/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 17:01:41 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/19 17:23:00 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack			*ft_ps_create_new_node(int val)
{
	t_stack *new;

	if ((new = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	new->val = val;
	new->i = 0;
	new->sort = 1;
	new->next = NULL;
	return (new);
}

t_stack			*ft_ps_get_last_node(t_stack *st)
{
	while (st->next)
		st = st->next;
	return (st);
}

int				ft_ps_get_count_nodes(t_stack *st)
{
	int count;

	count = 0;
	while (st)
	{
		st = st->next;
		count++;
	}
	return (count);
}

static void		ft_ps_create_stack_a(int ac, char **av, t_stacks *sts)
{
	int i;
	int cur_val;

	av = ac == 2 ? ft_strsplit(av[1], ' ') : av;
	i = ac == 2 ? 0 : 1;
	while ((ac == 2 ? (int)av[i] : i < ac))
	{
		if (ft_strcmp(av[i], "-v") == 0)
			sts->flag_v = 1;
		else
		{
			cur_val = ft_atoi(av[i]);
			if (ft_ps_is_valid_int(cur_val, av[i]) == 0 ||
				ft_ps_is_not_dupl(sts->a, cur_val) == 0)
				ft_ps_put_error(&sts, ft_free_array(ac == 2 ? av : NULL, 1));
			if ((ft_ps_stack_push_back_int(&sts->a, cur_val)) == NULL)
				ft_ps_put_error(&sts, ft_free_array(ac == 2 ? av : NULL, 1));
		}
		i++;
	}
	ft_free_array(ac == 2 ? av : NULL, 1);
}

t_stacks		*ft_ps_create_stacks(int ac, char **av)
{
	t_stacks *sts;

	if ((sts = (t_stacks*)malloc(sizeof(t_stacks))) == NULL)
		ft_ps_put_error(&sts, 1);
	sts->a = NULL;
	sts->b = NULL;
	sts->flag_v = 0;
	sts->cmds_cnt = 0;
	sts->cmd_print = 0;
	ft_ps_create_stack_a(ac, av, sts);
	return (sts);
}
