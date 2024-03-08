/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:51:53 by tlay              #+#    #+#             */
/*   Updated: 2024/03/07 17:45:32 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Lorsque rotation dans le meme sens, prendre le plus grand des 2
int	ft_case_rrarrb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	int	i;
	int	cost_a;
	int	cost_b;

	i = 0;
	cost_a = ft_find_index(stack_a, nb);
	cost_b = ft_find_place_b(stack_b, nb);
	if (cost_a > 0)
		cost_a = my_lstsize(stack_a) - ft_find_index(stack_a, nb);
	if (cost_b > 0)
		cost_b = my_lstsize(stack_b) - ft_find_place_b(stack_b, nb);
	if (cost_a > cost_b)
		i = cost_a;
	else
		i = cost_b;
	return (i);
}

int	ft_case_rarb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	int	i;
	int	cost_a;
	int	cost_b;

	i = 0;
	cost_a = ft_find_index(stack_a, nb);
	cost_b = ft_find_place_b(stack_b, nb);
	if (cost_a >= cost_b)
		i = cost_a;
	if (cost_b >= cost_a)
		i = cost_b;
	return (i);
}

int	ft_case_rrarb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	int	i;
	int	cost_a;
	int	cost_b;

	i = 0;
	cost_a = ft_find_index(stack_a, nb);
	cost_b = ft_find_place_b(stack_b, nb);
	if (cost_a > 0)
		cost_a = my_lstsize(stack_a) - ft_find_index(stack_a, nb);
	i = cost_a + cost_b;
	return (i);
}

int	ft_case_rarrb(t_stack *stack_a, t_stack *stack_b, int nb)
{
	int	i;
	int	cost_a;
	int	cost_b;

	i = 0;
	cost_a = ft_find_index(stack_a, nb);
	cost_b = ft_find_place_b(stack_b, nb);
	if (cost_b > 0)
		cost_b = my_lstsize(stack_b) - ft_find_place_b(stack_b, nb);
	i = cost_a + cost_b;
	return (i);
}
