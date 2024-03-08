/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:18:53 by tlay              #+#    #+#             */
/*   Updated: 2024/02/19 16:04:47 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*my_lstnew(int value)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->value = value;
	element->next = NULL;
	return (element);
}

void	my_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = NULL;
}

void	my_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*element;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	element = *lst;
	while (element && element->next)
		element = element->next;
	element->next = new;
	new->next = NULL;
	return ;
}

void	my_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	my_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}
