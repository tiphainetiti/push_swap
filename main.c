/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:05:19 by tlay              #+#    #+#             */
/*   Updated: 2024/03/07 18:58:08 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Afficher ma stack
// void	ft_print_stack(t_stack *to_print, char *when)
//{
//	t_stack	*stack;

//	stack = to_print;
//	if (!stack)
//		return ;
//	write(1, "stack ", 6);
//	printf("%s\n", when);
//	while (stack)
//	{
//		printf("%d\n", stack->value);
//		stack = stack->next;
//	}
//	write(1, "\n", 1);
//}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	(void)av;
	if (ac >= 2)
	{
		ft_stack_init(av, &stack_a);
		// ft_print_stack(stack_a, "a AVANT :");
		ft_algo(&stack_a, &stack_b);
		// ft_print_stack(stack_a, "a apres ALGO");
		// ft_print_stack(stack_b, "b apres ALGO");
	}
	my_lstclear(&stack_a);
	my_lstclear(&stack_b);
	return (0);
}
