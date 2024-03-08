/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:14:53 by tlay              #+#    #+#             */
/*   Updated: 2024/03/08 17:19:46 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_apply_line(t_stack *stack_a, t_stack *stack_b, char *line)
{
	char	*next_command;

	next_command = get_next_line(0);
	if (line[0] == 's' && line[2] == '\n')
		ft_line_s(stack_a, stack_a, line);
	else if (line[0] == 'r' && line[2] == '\n')
		ft_line_r(stack_a, stack_a, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_line_rr(stack_a, stack_a, line);
	else if (line[0] == 'p' && line[2] == '\n')
		ft_line_p(stack_a, stack_a, line);
	else
		ft_error();
	return (next_command);
}

void	ft_check(t_stack *stack_a, t_stack *stack_b, char *line)
{
	char	*tmp;

	while (line && line != NULL)
	{
		tmp = line;
		line = ft_apply_line(stack_a, stack_b, tmp);
		free(tmp);
	}
	if (stack_b)
		error;
	else if (ft_check_sorted(stack_a) == 1)
		error;
	else
		write(1, "OK\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		ft_stack_init(av, stack_a);
	line = get_next_line(0);
	if (!line && (ft_check_sorted(stack_a) == 1))
		write(1, "KO\n", 3);
	else if (!line && (ft_check_sorted(stack_a) == 0))
		write(1, "OK\n", 3);
	else
		ft_check(stack_a, stack_a, line);
	if (ft_check_sorted(stack_a) == 1)
		error;
	else
		write(1, "OK\n", 3);
	my_lstclear(&stack_a);
	my_lstclear(&stack_b);
}
