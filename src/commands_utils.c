/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:32:50 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/19 16:18:15 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_ps_cmd_apply_s(t_stack **stack)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->val;
		(*stack)->val = (*stack)->next->val;
		(*stack)->next->val = tmp;
		return (1);
	}
	return (-1);
}

int	ft_ps_cmd_apply_r(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_ps_stack_push_back(stack, ft_ps_stack_pop_front(stack));
		return (1);
	}
	return (-1);
}

int	ft_ps_cmd_apply_rr(t_stack **stack)
{
	if (*stack && (*stack)->next)
	{
		ft_ps_stack_push_front(stack, ft_ps_stack_pop_back(stack));
		return (1);
	}
	return (-1);
}

int	ft_ps_cmd_apply_p(t_stack **from, t_stack **to)
{
	if (*from)
	{
		ft_ps_stack_push_front(to, ft_ps_stack_pop_front(from));
		return (1);
	}
	return (-1);
}
