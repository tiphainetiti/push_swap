/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:45:02 by tlay              #+#    #+#             */
/*   Updated: 2024/03/12 17:46:03 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap a : inverse les 2 premiers node de a
void	ft_sa(t_stack **stack_a, int j)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	if (!((*stack_a)->next))
		my_lstadd_back(stack_a, first);
	else
	{
		second = *stack_a;
		*stack_a = (*stack_a)->next;
		my_lstadd_front(stack_a, first);
		my_lstadd_front(stack_a, second);
	}
	if (j == 0)
		write(1, "sa\n", 3);
}

// swap b :  inverse les 2 premiers node de b
void	ft_sb(t_stack **stack_b, int j)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	if (!((*stack_b)->next))
		my_lstadd_back(stack_b, first);
	else
	{
		second = *stack_b;
		*stack_b = (*stack_b)->next;
		my_lstadd_front(stack_b, first);
		my_lstadd_front(stack_b, second);
	}
	if (j == 0)
		write(1, "sb\n", 3);
}

// ss : sa + sb
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int j)
{
	j = 1;
	ft_sa(stack_a, j);
	ft_sb(stack_b, j);
	write(1, "ss\n", 3);
}
