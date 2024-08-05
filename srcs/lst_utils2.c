/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:53:32 by tlay              #+#    #+#             */
/*   Updated: 2024/08/05 22:11:58 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	my_lstsize(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack	*my_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

// Trouver la valeur du minimum dans la stack
int	ft_min(t_stack *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (i > stack->value)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}

// Trouver la valeur du maximum dans la stack
int	ft_max(t_stack *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (i < stack->value)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}

// Trouver l'index d'un nombre dans la stack
int	ft_find_index(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	while (stack->value != nb)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
