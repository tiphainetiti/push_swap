/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:16:37 by tlay              #+#    #+#             */
/*   Updated: 2024/08/05 22:11:58 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_b))
		return ;
	ft_nb_on_top_b(stack_b, ft_max(*stack_b));
	while ((*stack_b))
	{
		if (ft_find_place_a(*stack_a, (*stack_b)->value) == 0)
			ft_pa(stack_a, stack_b, 0);
		else
			ft_rra(stack_a, 0);
	}
}

void	ft_push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	if (my_lstsize(*stack_a) > 3 && (ft_check_sorted_a(*stack_a) == 1))
		ft_pb(stack_a, stack_b, 0);
	if (my_lstsize(*stack_a) > 3 && (ft_check_sorted_a(*stack_a) == 1))
		ft_pb(stack_a, stack_b, 0);
	while (stack_a && my_lstsize(*stack_a) > 3
		&& ft_check_sorted_a(*stack_a) == 1)
		ft_apply_case(stack_a, stack_b);
	if (my_lstsize(*stack_a) <= 3 && (ft_check_sorted_a(*stack_a) == 1))
		ft_small_sort(stack_a);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (my_lstsize(*stack_a) <= 3)
		ft_small_sort(stack_a);
	else
	{
		ft_push_a_to_b(stack_a, stack_b);
		ft_push_b_to_a(stack_a, stack_b);
		ft_nb_on_top_a(stack_a, ft_min(*stack_a));
	}
	if (ft_check_sorted_a(*stack_a) == 1)
		write(2, "Error\n", 6);
}
