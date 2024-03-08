/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 02:00:30 by tlay              #+#    #+#             */
/*   Updated: 2024/03/07 18:51:47 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Trouver l'index où push dans la stack_b : DECROISSANT
// Si entre le 1er et le dernier
// Si nouveau max ou min
// Tant que pas compris entre node1 et node 2, i++
int	ft_find_place_b(t_stack *stack_b, int nb)
{
	int		i;
	t_stack	*next_node;

	i = 1;
	if (nb > stack_b->value && nb < my_lstlast(stack_b)->value)
		i = 0;
	else if (nb < ft_min(stack_b) || nb > ft_max(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		next_node = stack_b->next;
		while (nb > stack_b->value || nb < next_node->value)
		{
			stack_b = stack_b->next;
			next_node = stack_b->next;
			i++;
		}
	}
	return (i);
}

// Trouver l'index où push dans la stack_a : CROISSANT
int	ft_find_place_a(t_stack *stack_a, int nb)
{
	int		i;
	t_stack	*next_node;

	i = 1;
	if (nb < stack_a->value && nb > my_lstlast(stack_a)->value)
		i = 0;
	else if (nb < ft_min(stack_a) || nb > ft_max(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		next_node = stack_a->next;
		while (nb < stack_a->value || nb > next_node->value)
		{
			stack_a = stack_a->next;
			next_node = stack_a->next;
			i++;
		}
	}
	return (i);
}
