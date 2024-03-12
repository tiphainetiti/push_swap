/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_rev_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:59:51 by tlay              #+#    #+#             */
/*   Updated: 2024/03/12 17:45:21 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// reverse rotate a : Decale vers le bas, le dernier devient le premier
void	ft_rra(t_stack **stack_a, int j)
{
	t_stack	*last;
	t_stack	*current;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	current = *stack_a;
	while (current->next && current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (j == 0)
		write(1, "rra\n", 4);
}

// reverse rotate b : Decale vers le bas, le dernier devient le premier
void	ft_rrb(t_stack **stack_b, int j)
{
	t_stack	*last;
	t_stack	*current;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	current = *stack_b;
	while (current->next && current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (j == 0)
		write(1, "rrb\n", 4);
}

// rrr : rra + rrb
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int j)
{
	j = 1;
	ft_rra(stack_a, j);
	ft_rrb(stack_b, j);
	write(1, "rrr\n", 4);
}
