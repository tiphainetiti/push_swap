/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:40:03 by tlay              #+#    #+#             */
/*   Updated: 2024/03/07 18:54:01 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cheappest(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		cheappest;

	tmp = stack_a;
	cheappest = ft_case_rarb(stack_a, stack_b, stack_a->value);
	while (tmp)
	{
		if (cheappest > ft_case_rarb(stack_a, stack_b, tmp->value))
			cheappest = ft_case_rarb(stack_a, stack_b, tmp->value);
		if (cheappest > ft_case_rrarrb(stack_a, stack_b, tmp->value))
			cheappest = ft_case_rrarrb(stack_a, stack_b, tmp->value);
		if (cheappest > ft_case_rrarb(stack_a, stack_b, tmp->value))
			cheappest = ft_case_rrarb(stack_a, stack_b, tmp->value);
		if (cheappest > ft_case_rarrb(stack_a, stack_b, tmp->value))
			cheappest = ft_case_rarrb(stack_a, stack_b, tmp->value);
		tmp = tmp->next;
	}
	return (cheappest);
}

// On a notre meilleure combinaison,
// c'est le chiffre le plus bas que l'on trouve en tournant dans la
// stack, donc en tournant dans la stack,
// on identifie de quel cas il s 'agit pour l' appliquer
void	ft_apply_case(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheappest;

	while (my_lstsize(*stack_a) > 3 && ft_check_sorted(*stack_a) == 1)
	{
		tmp = *stack_a;
		cheappest = ft_cheappest(*stack_a, *stack_b);
		while (cheappest >= 0)
		{
			if (cheappest == ft_case_rarb(*stack_a, *stack_b, tmp->value))
				cheappest = ft_apply_rarb(stack_a, stack_b, tmp->value);
			else if (cheappest == ft_case_rrarrb(*stack_a, *stack_b,
					tmp->value))
				cheappest = ft_apply_rrarrb(stack_a, stack_b, tmp->value);
			else if (cheappest == ft_case_rrarb(*stack_a, *stack_b, tmp->value))
				cheappest = ft_apply_rrarb(stack_a, stack_b, tmp->value);
			else if (cheappest == ft_case_rarrb(*stack_a, *stack_b, tmp->value))
				cheappest = ft_apply_rarrb(stack_a, stack_b, tmp->value);
			else
				tmp = tmp->next;
		}
	}
}
