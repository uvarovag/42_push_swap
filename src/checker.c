/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:40:07 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/21 18:02:45 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		main(int ac, char **av)
{
	t_stacks	*sts;
	char		*cur_com;

	cur_com = NULL;
	sts = ft_ps_create_stacks(ac, av);
	sts->cmd_print = 0;
	if (sts->a == NULL)
		exit(ft_ps_stacks_free(&sts, 0));
	while (get_next_line(0, &cur_com))
	{
		ft_ps_cmd_apply_cnt(cur_com, 1, sts);
		if (cur_com)
			free(cur_com);
	}
	if (ft_ps_is_sort_stacks(sts))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (ft_ps_stacks_free(&sts, 0));
}
