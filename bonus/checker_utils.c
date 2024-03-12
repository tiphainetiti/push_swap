/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:56:19 by tlay              #+#    #+#             */
/*   Updated: 2024/03/12 16:53:10 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_checker_error(t_stack **stack_a, t_stack **stack_b, char *line)
{
	my_lstclear(stack_a);
	my_lstclear(stack_b);
	free(line);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
