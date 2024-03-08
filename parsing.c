/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:04:25 by tlay              #+#    #+#             */
/*   Updated: 2024/03/06 11:30:06 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parsing(char *table)
{
	int	i;

	i = 0;
	if (ft_check_digit(&table[i]) == 1
		|| ft_check_overflow(ft_atol(&table[i])) == 1
		|| ft_check_overflow_ull(ft_atoull(&table[i]), table) == 1
		|| ft_check_missing_space(table) == 1)
		return (1);
	return (0);
}
