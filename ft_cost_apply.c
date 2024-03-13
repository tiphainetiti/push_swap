/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:27:09 by tlay              #+#    #+#             */
/*   Updated: 2024/03/13 16:46:14 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_apply_rrarrb(t_stack **stack_a, t_stack **stack_b, int cheap_node)
{
	while ((*stack_a)->value != cheap_node && (ft_find_place_b(*stack_b,
				cheap_node) > 0))
		ft_rrr(stack_a, stack_b, 1);
	while ((*stack_a)->value != cheap_node)
		ft_rra(stack_a, 0);
	while (ft_find_place_b(*stack_b, cheap_node) > 0)
		ft_rrb(stack_b, 0);
	ft_pb(stack_a, stack_b, 0);
	return (-1);
}

int	ft_apply_rarb(t_stack **stack_a, t_stack **stack_b, int cheap_node)
{
	while ((*stack_a)->value != cheap_node && ft_find_place_b(*stack_b,
			cheap_node) > 0)
		ft_rr(stack_a, stack_b, 1);
	while ((*stack_a)->value != cheap_node)
		ft_ra(stack_a, 0);
	while (ft_find_place_b(*stack_b, cheap_node) > 0)
		ft_rb(stack_b, 0);
	ft_pb(stack_a, stack_b, 0);
	return (-1);
}

int	ft_apply_rrarb(t_stack **stack_a, t_stack **stack_b, int cheap_node)
{
	while ((*stack_a)->value != cheap_node)
		ft_rra(stack_a, 0);
	while (ft_find_place_b(*stack_b, cheap_node) > 0)
		ft_rb(stack_b, 0);
	ft_pb(stack_a, stack_b, 0);
	return (-1);
}

int	ft_apply_rarrb(t_stack **stack_a, t_stack **stack_b, int cheap_node)
{
	while ((*stack_a)->value != cheap_node)
		ft_ra(stack_a, 0);
	while (ft_find_place_b(*stack_b, cheap_node) > 0)
		ft_rrb(stack_b, 0);
	ft_pb(stack_a, stack_b, 0);
	return (-1);
}
