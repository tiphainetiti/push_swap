/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:47:35 by tlay              #+#    #+#             */
/*   Updated: 2024/03/12 17:45:33 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate a : Decale vers le haut, le premier devient le dernier
void	ft_ra(t_stack **stack_a, int j)
{
	t_stack	*first;
	t_stack	*current;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	current = *stack_a;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

// rotate b : Decale vers le haut, le premier devient le dernier
void	ft_rb(t_stack **stack_b, int j)
{
	t_stack	*first;
	t_stack	*current;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	first = *stack_b;
	*stack_b = (*stack_b)->next;
	current = *stack_b;
	while (current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

// rr : ra + rb
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int j)
{
	j = 1;
	ft_ra(stack_a, j);
	ft_rb(stack_b, j);
	write(1, "rr\n", 3);
}
