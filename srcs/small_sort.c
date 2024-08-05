/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:45:23 by tlay              #+#    #+#             */
/*   Updated: 2024/08/05 22:11:58 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Algo pour trier les listes de 3 :
Si le 1er est le max ((3 2 1 / 3 1 2))
Si le 2e est le max ((1 3 2 / 2 3 1))
Si le 3e est le max((2 1 3))*/

void	ft_small_sort(t_stack **stack_a)
{
	if (ft_max(*stack_a) == (*stack_a)->value)
	{
		ft_ra(stack_a, 0);
		if (ft_check_sorted_a(*stack_a) == 1)
			ft_sa(stack_a, 0);
	}
	else if (ft_find_index(*stack_a, ft_max(*stack_a)) == 1)
	{
		ft_rra(stack_a, 0);
		if (ft_check_sorted_a(*stack_a) == 1)
			ft_sa(stack_a, 0);
	}
	else
		ft_sa(stack_a, 0);
}
