/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlay <tlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:49:05 by tlay              #+#    #+#             */
/*   Updated: 2024/02/05 18:56:19 by tlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	size;
	char	*table;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	table = (char *)malloc((size + 1) * sizeof(char));
	if (table == NULL)
		return (NULL);
	while (s1[i])
	{
		table[i] = s1[i];
		i++;
	}
	while (s2[j])
		table[i++] = s2[j++];
	table[i] = '\0';
	return (table);
}
//#include <stdio.h>

// int	main(void)
//{
//	const char	*s1;
//	const char	*s2;

//	s1 = "123 445";
//	s2 = "678";
//	printf("%s\n", ft_strjoin(s1, s2));
//	return (0);
//}
