/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:21:35 by tlay              #+#    #+#             */
/*   Updated: 2024/03/06 11:30:36 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_doubles(t_stack *stack_a, int new)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->value == new)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (ft_isdigit((int)str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_overflow(long new)
{
	int	i;

	if (new > 2147483647 || new < -2147483648)
		return (1);
	i = ft_size_int(new);
	if (new < 0)
	{
		if (i > 11)
			return (1);
	}
	else if (i > 10)
		return (1);
	return (0);
}

int	ft_check_overflow_ull(unsigned long long new, char *table)
{
	int	i;
	int	j;

	i = ft_size_ull(new);
	j = ft_strlen(table);
	if (new > 2147483647 && i < j)
		return (1);
	if (new < 0)
	{
		if (i > 11)
			return (1);
	}
	else
	{
		if (i > 10)
			return (1);
	}
	return (0);
}

int	ft_check_missing_space(char *table)
{
	int	i;

	i = 1;
	while (table[i])
	{
		if (ft_isdigit(table[i - 1]) == 1 && (table[i] == '-'
				|| table[i] == '+'))
			return (1);
		i++;
	}
	return (0);
}
