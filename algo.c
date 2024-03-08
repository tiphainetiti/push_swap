/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:16:37 by tlay              #+#    #+#             */
/*   Updated: 2024/03/07 18:54:44 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push dans A tant que target, puis rev rotate A
void	ft_push_B_to_A(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_b))
		return ;
	ft_nb_on_topB(stack_b, ft_max(*stack_b));
	while ((*stack_b))
	{
		if (ft_find_place_a(*stack_a, (*stack_b)->value) == 0)
			ft_pa(stack_a, stack_b);
		else
			ft_rra(stack_a, 0);
	}
}

void	ft_push_A_to_B(t_stack **stack_a, t_stack **stack_b)
{
	if (my_lstsize(*stack_a) > 3 && (ft_check_sorted(*stack_a) == 1))
		ft_pb(stack_a, stack_b);
	if (my_lstsize(*stack_a) > 3 && (ft_check_sorted(*stack_a) == 1))
		ft_pb(stack_a, stack_b);
	while (stack_a && my_lstsize(*stack_a) > 3
		&& ft_check_sorted(*stack_a) == 1)
		ft_apply_case(stack_a, stack_b);
	if (my_lstsize(*stack_a) <= 3 && (ft_check_sorted(*stack_a) == 1))
		ft_small_sort(stack_a);
}

void	ft_algo(t_stack **stack_a, t_stack **stack_b)
{
	if (my_lstsize(*stack_a) <= 3)
	{
		ft_small_sort(stack_a);
		return ;
	}
	else
	{
		ft_push_A_to_B(stack_a, stack_b);
		ft_push_B_to_A(stack_a, stack_b);
		ft_nb_on_topA(stack_a, ft_min(*stack_a));
	}
}
