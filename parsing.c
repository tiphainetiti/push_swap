/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:04:25 by tlay              #+#    #+#             */
/*   Updated: 2024/03/13 15:57:13 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculer la longueur de mon argv sans compter les 0
int	ft_strlen_ps(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] == '-')
		i++;
	while (s[i + j])
	{
		if (s[i + j] == '0' && i == 1)
		{
			while (s[i + j] == '0')
				j++;
		}
		if (s[i + j])
			i++;
	}
	return (i);
}

int	ft_parsing(char *table)
{
	if (ft_check_digit(table) == 1 || ft_check_overflow(ft_atol(table)) == 1
		|| ft_check_overflow_ull(ft_atoull(table), table) == 1
		|| ft_check_missing_space(table) == 1)
		return (1);
	if (table[0] == '-')
	{
		if (ft_strlen_ps(table) > 11)
			return (1);
	}
	return (0);
}
