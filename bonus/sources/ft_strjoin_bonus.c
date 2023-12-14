/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:23:49 by mgama             #+#    #+#             */
/*   Updated: 2023/12/15 00:24:45 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	void	*lst_dst;

	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	lst_dst = dst;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (lst_dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	if (!s2)
		return (free(s1), NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(
			sizeof(char) * (i + j + 1));
	if (!str)
		return (free(s1), NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j);
	ft_memset(str + i + j, '\0', sizeof(char));
	free(s1);
	return (str);
}
