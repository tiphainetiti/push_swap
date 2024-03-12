/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:32:22 by tlay              #+#    #+#             */
/*   Updated: 2024/03/12 10:29:43 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *stack_a, char *all_av, char **table)
{
	if (!stack_a)
	{
		free(all_av);
		ft_free(table);
		write(2, "Error\n", 6);
	}
	else
	{
		my_lstclear(&stack_a);
		free(all_av);
		ft_free(table);
		write(2, "Error\n", 6);
	}
	exit(EXIT_FAILURE);
}

void	ft_free(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}
