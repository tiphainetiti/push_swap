/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:56:35 by tlay              #+#    #+#             */
/*   Updated: 2024/08/05 22:11:58 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*my_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	size;
	char	*table;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	i = -1;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	table = (char *)malloc((size + 1) * sizeof(char));
	if (table == NULL)
		return (NULL);
	while (s1[++i])
		table[i] = s1[i];
	table[i++] = ' ';
	while (s2[j])
		table[i++] = s2[j++];
	table[i] = '\0';
	return (table);
}

char	*ft_free_strjoin(char *all_av, char *new_av)
{
	char	*tmp;

	tmp = my_strjoin(all_av, new_av);
	free(all_av);
	return (tmp);
}
