/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:02:06 by tlay              #+#    #+#             */
/*   Updated: 2024/02/13 16:26:27 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ajouter les arguments un a un + free l'ancien strjoin
static char	*ft_add_av(char *all_av, char *av, char *tmp)
{
	char	*tmp2;

	tmp2 = ft_free_strjoin(all_av, "");
	all_av = tmp2;
	tmp = ft_free_strjoin(all_av, av);
	all_av = tmp;
	return (all_av);
}

// Lorsque qu'il n'y a qu'un argument ou un seul a ajouter
static char	*ft_just_one_av(char *av, char *all_av, char *tmp)
{
	if (!all_av)
		all_av = ft_strdup(av);
	else
	{
		tmp = ft_free_strjoin(all_av, av);
		all_av = tmp;
	}
	return (all_av);
}

// Rassembler tous les arguments en une chaine de caracteres
static char	*ft_gather_av(char **av)
{
	char	*all_av;
	char	*tmp;
	int		i;

	all_av = NULL;
	tmp = NULL;
	i = 1;
	while (av[i])
	{
		if (!av[i + 1])
		{
			all_av = ft_just_one_av(av[i], all_av, tmp);
			break ;
		}
		if (!all_av)
			all_av = ft_strdup(av[i]);
		else
			all_av = ft_add_av(all_av, av[i], tmp);
		i++;
	}
	return (all_av);
}

// Gestion d'une chaine vide
void	ft_empty_table(char *all_av, char **table)
{
	int	i;

	i = 0;
	if (table[0] == NULL)
	{
		ft_error_free(all_av, table);
		exit(EXIT_FAILURE);
	}
}

// Initialisation de la stack
void	ft_stack_init(char **av, t_stack **stack_a)
{
	char	*all_av;
	char	**table;
	int		i;

	all_av = NULL;
	table = NULL;
	i = 0;
	all_av = ft_gather_av(av);
	table = my_split(all_av, ' ');
	ft_empty_table(all_av, table);
	while (table[i])
	{
		if (ft_parsing(table[i]) == 0 && ft_check_doubles(*stack_a,
				ft_atoll(table[i])) == 0)
			my_lstadd_back(stack_a, my_lstnew(ft_atoll(table[i])));
		else
		{
			my_lstclear(stack_a);
			ft_error(*stack_a, all_av, table);
		}
		i++;
	}
	free(all_av);
	ft_free(table);
}
