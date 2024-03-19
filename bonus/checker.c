/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:14:53 by tlay              #+#    #+#             */
/*   Updated: 2024/03/18 14:03:24 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_sub(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[2] == 'a')
		ft_rra(stack_a, 1);
	else if (line[2] == 'b')
		ft_rrb(stack_b, 1);
	else if (line[2] == 'r')
		ft_rrr(stack_a, stack_b, 2);
}

char	*ft_apply_line(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(stack_a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(stack_a, stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(stack_a, stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(stack_a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(stack_a, stack_b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(stack_a, stack_b, 2);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(stack_a, stack_b, 2);
	else
		ft_checker_error(stack_a, stack_b, line);
	return (get_next_line(0));
}

void	ft_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_apply_line(stack_a, stack_b, line);
		free(tmp);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	else if (ft_check_sorted_a(*stack_a) == 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	(void)ac;
	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
		ft_stack_init(av, &stack_a);
	else if (ac < 2)
		return (0);
	line = get_next_line(0);
	if (!line && (ft_check_sorted_a(stack_a) == 1))
		write(1, "KO\n", 3);
	else if (!line && (ft_check_sorted_a(stack_a) == 0))
		write(1, "OK\n", 3);
	else
		ft_check(&stack_a, &stack_b, line);
	my_lstclear(&stack_a);
	my_lstclear(&stack_b);
	return (0);
}
