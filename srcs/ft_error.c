/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:32:22 by tlay              #+#    #+#             */
/*   Updated: 2024/08/05 22:11:58 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(t_stack *stack_a, char *all_av, char **table)
{
	if (!stack_a)
		ft_error_free(all_av, table);
	else
	{
		my_lstclear(&stack_a);
		ft_error_free(all_av, table);
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

void	ft_error_free(char *all_av, char **table)
{
	free(all_av);
	ft_free(table);
	write(2, "Error\n", 6);
}
