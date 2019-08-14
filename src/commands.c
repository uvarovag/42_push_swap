/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:07:40 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/21 18:08:12 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			ft_ps_print_stack(t_stacks *sts)
{
	t_stack *st_a;
	t_stack *st_b;

	st_a = sts->a;
	st_b = sts->b;
	while (st_a || st_b)
	{
		if (st_a)
			ft_putnbr(st_a->val);
		else
			ft_putchar('-');
		ft_putstr(" | ");
		if (st_b)
			ft_putnbr(st_b->val);
		else
			ft_putchar('-');
		ft_putchar('\n');
		st_a = st_a ? st_a->next : NULL;
		st_b = st_b ? st_b->next : NULL;
	}
	ft_putchar('\n');
}

static void		ft_ps_cmd_print(char *com)
{
	ft_putstr(com);
	ft_putchar('\n');
}

static int		ft_ps_cmd_apply(char *com, t_stacks *sts)
{
	int	len;
	int	res;

	len = ft_strlen(com);
	res = 0;
	if (len == 2 && com[0] == 's' && (com[1] == 's' || com[1] == 'a'))
		res = ft_ps_cmd_apply_s(&sts->a);
	if (len == 2 && com[0] == 's' && (com[1] == 's' || com[1] == 'b'))
		res = ft_ps_cmd_apply_s(&sts->b);
	if (len == 2 && com[0] == 'p' && com[1] == 'a')
		res = ft_ps_cmd_apply_p(&sts->b, &sts->a);
	if (len == 2 && com[0] == 'p' && com[1] == 'b')
		res = ft_ps_cmd_apply_p(&sts->a, &sts->b);
	if (len == 2 && com[0] == 'r' && (com[1] == 'r' || com[1] == 'a'))
		res = ft_ps_cmd_apply_r(&sts->a);
	if (len == 2 && com[0] == 'r' && (com[1] == 'r' || com[1] == 'b'))
		res = ft_ps_cmd_apply_r(&sts->b);
	if (len == 3 && com[0] == 'r' && com[1] == 'r' &&
		(com[2] == 'r' || com[2] == 'a'))
		res = ft_ps_cmd_apply_rr(&sts->a);
	if (len == 3 && com[0] == 'r' && com[1] == 'r' &&
		(com[2] == 'r' || com[2] == 'b'))
		res = ft_ps_cmd_apply_rr(&sts->b);
	return (res == 0 ? 0 : 1);
}

void			ft_ps_cmd_apply_cnt(char *com, int cnt, t_stacks *sts)
{
	int	i;

	i = ft_abs(cnt);
	while (i)
	{
		if (ft_ps_cmd_apply(com, sts))
		{
			if (sts->cmd_print == 1)
				ft_ps_cmd_print(com);
			if (sts->cmd_print == 0 && sts->flag_v == 1)
				ft_ps_print_stack(sts);
			sts->cmds_cnt++;
		}
		else
			ft_ps_put_error(&sts, 0);
		i--;
	}
}
