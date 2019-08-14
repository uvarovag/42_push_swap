/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:02:10 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/17 20:04:13 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			ft_ps_stack_push_back(t_stack **stack, t_stack *new)
{
	t_stack *last;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_ps_get_last_node(*stack);
	last->next = new;
}

void			ft_ps_stack_push_front(t_stack **stack, t_stack *new)
{
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

t_stack			*ft_ps_stack_push_back_int(t_stack **stack, int val)
{
	t_stack *new;

	if ((new = ft_ps_create_new_node(val)) == NULL)
		return (NULL);
	ft_ps_stack_push_back(stack, new);
	return (*stack);
}
