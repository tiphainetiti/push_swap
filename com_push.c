/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:58 by tlay              #+#    #+#             */
/*   Updated: 2024/03/07 16:27:18 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push a : prend b met au dessus de a
void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	my_lstadd_front(stack_a, tmp);
	write(1, "pa\n", 3);
}

// push b : prend a met au dessus de b
void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	my_lstadd_front(stack_b, tmp);
	write(1, "pb\n", 3);
}
