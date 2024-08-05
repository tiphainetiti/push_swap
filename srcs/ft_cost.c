/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:40:03 by tlay              #+#    #+#             */
/*   Updated: 2024/08/05 22:11:58 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Parcourir la stack en calculant chaque combinaison de commandes
// afin de trouver la moins chere
int	ft_cheappest(t_stack *stack_a, t_stack *stack_b) {
  t_stack *tmp;
  int cheappest;

  tmp = stack_a;
  cheappest = ft_case_rarb(stack_a, stack_b, stack_a->value);
  while (tmp) {
    if (cheappest > ft_case_rarb(stack_a, stack_b, tmp->value))
      cheappest = ft_case_rarb(stack_a, stack_b, tmp->value);
    if (cheappest > ft_case_rrarrb(stack_a, stack_b, tmp->value))
      cheappest = ft_case_rrarrb(stack_a, stack_b, tmp->value);
    if (cheappest > ft_case_rrarb(stack_a, stack_b, tmp->value))
      cheappest = ft_case_rrarb(stack_a, stack_b, tmp->value);
    if (cheappest > ft_case_rarrb(stack_a, stack_b, tmp->value))
      cheappest = ft_case_rarrb(stack_a, stack_b, tmp->value);
    tmp = tmp->next;
  }
  return (cheappest);
}

// Identifier et appliquer la combinaison la moins chere
void	ft_apply_case(t_stack **stack_a, t_stack **stack_b) {
  t_stack *tmp;
  int cheappest;

  while (my_lstsize(*stack_a) > 3 && ft_check_sorted_a(*stack_a) == 1) {
    tmp = *stack_a;
    cheappest = ft_cheappest(*stack_a, *stack_b);
    while (cheappest >= 0) {
      if (cheappest == ft_case_rarb(*stack_a, *stack_b, tmp->value))
        cheappest = ft_apply_rarb(stack_a, stack_b, tmp->value);
      else if (cheappest == ft_case_rrarrb(*stack_a, *stack_b, tmp->value))
        cheappest = ft_apply_rrarrb(stack_a, stack_b, tmp->value);
      else if (cheappest == ft_case_rrarb(*stack_a, *stack_b, tmp->value))
        cheappest = ft_apply_rrarb(stack_a, stack_b, tmp->value);
      else if (cheappest == ft_case_rarrb(*stack_a, *stack_b, tmp->value))
        cheappest = ft_apply_rarrb(stack_a, stack_b, tmp->value);
      else
        tmp = tmp->next;
    }
  }
}
