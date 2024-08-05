/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:12:14 by tiphainelay       #+#    #+#             */
/*   Updated: 2024/08/05 22:11:58 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Avoir l'index de la mediane
int	ft_med_index(t_stack *stack)
{
	int	med;

	med = my_lstsize(stack) / 2 + 1;
	return (med);
}

// Mettre un nombre on top de la stack_a
void	ft_nb_on_top_a(t_stack **stack_a, int nb)
{
	int	i;

	i = ft_find_index(*stack_a, nb);
	while ((*stack_a)->value != nb)
	{
		if (i <= ft_med_index(*stack_a))
			ft_ra(stack_a, 0);
		else
			ft_rra(stack_a, 0);
	}
}

// Mettre un nombre on top de la stack_b
void	ft_nb_on_top_b(t_stack **stack_b, int nb)
{
	int	i;

	i = ft_find_index(*stack_b, nb);
	while ((*stack_b)->value != nb)
	{
		if (i <= ft_med_index(*stack_b))
			ft_rb(stack_b, 0);
		else
			ft_rrb(stack_b, 0);
	}
}

// Checker si la stack_a est trie : ordre croissant
int	ft_check_sorted_a(t_stack *stack_a)
{
	int	i;

	i = stack_a->value;
	while (stack_a)
	{
		if (i > stack_a->value)
			return (1);
		i = stack_a->value;
		stack_a = stack_a->next;
	}
	return (0);
}

// Checker si la stack_b est trie : ordre decroissant
int	ft_check_sorted_b(t_stack *stack_b)
{
	int	prev_value;

	prev_value = stack_b->value;
	stack_b = stack_b->next;
	while (stack_b)
	{
		if (prev_value < stack_b->value)
			return (1);
		prev_value = stack_b->value;
		stack_b = stack_b->next;
	}
	return (0);
}
