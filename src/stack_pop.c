/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 15:02:06 by vsanta            #+#    #+#             */
/*   Updated: 2019/07/19 13:55:54 by vsanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack			*ft_ps_stack_pop_front(t_stack **stack)
{
	t_stack *tmp;

	if (*stack == NULL)
		return (NULL);
	tmp = *stack;
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
		*stack = tmp->next;
	tmp->next = NULL;
	return (tmp);
}

t_stack			*ft_ps_stack_pop_back(t_stack **stack)
{
	t_stack *pre_last;
	t_stack *tmp;

	pre_last = *stack;
	tmp = *stack;
	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		while (pre_last->next && pre_last->next->next)
			pre_last = pre_last->next;
		tmp = pre_last->next;
		pre_last->next = NULL;
	}
	return (tmp);
}
