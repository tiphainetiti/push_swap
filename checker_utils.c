/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:56:19 by tlay              #+#    #+#             */
/*   Updated: 2024/03/08 17:03:31 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_line_s(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (line[1] == 'a')
		ft_sa(&stack_a, 0);
	else
		ft_sb(&stack_b, 0);
}

void	ft_line_r(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (line[1] == 'a')
		ft_ra(&stack_a, 0);
	else if (line[1] == 'b')
		ft_rb(&stack_b, 0);
	else
		ft_rr(&stack_a, &stack_b, 1);
}

void	ft_line_rr(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (line[2] == 'a')
		ft_rra(&stack_a, 0);
	else if (line[2] == 'b')
		ft_rrb(&stack_b, 0);
	else
		ft_rrr(&stack_a, &stack_b, 1);
}

void	ft_line_p(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (line[1] == 'a')
		ft_pa(&stack_a, 0);
	else
		ft_pb(&stack_b, 0);
}
