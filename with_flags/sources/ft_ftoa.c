/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:45:47 by mgama             #+#    #+#             */
/*   Updated: 2022/12/29 16:01:08 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_ftoa(double n, int afterpoint)
{
	int		ipart;
	double	fpart;
	char	*res;
	char	temp;
	int		i;
	int		j;
	int		k;
	int		to_int;
	char	str[10];
	int		is_negative;

	// Extract integer part
	ipart = (int)n;
	// Extract floating part
	fpart = n - (float)ipart;
	// Allocate memory for result string and initialize the result string to all zeros
	res = ft_calloc(20, sizeof(char));
	if (!res)
		return (NULL);
	// Convert integer part to string
	i = 0;
	is_negative = 0;
	if (ipart == 0)
	{
		res[i++] = '0';
	}
	// If the number is negative, add a minus sign and set a flag
	if (ipart < 0)
	{
		is_negative = 1;
		ipart = -ipart;
	}
	// Convert the integer part to a string by repeatedly dividing by 10 and adding the remainder to the result string
	while (ipart > 0)
	{
		res[i++] = (ipart % 10) + '0';
		ipart /= 10;
	}
	// If the number is negative, add the minus sign to the result string
	if (is_negative)
	{
		res[i++] = '-';
	}
	// Reverse the result string
	j = 0;
	k = i - 1;
	while (j < k)
	{
		temp = res[j];
		res[j] = res[k];
		res[k] = temp;
		j++;
		k--;
	}
	// Check for display option after point
	if (afterpoint != 0)
	{
		// Add dot
		ft_strcat(res, ".");
		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter is needed
		// to handle cases like 233.007
		fpart = fpart * ft_pow(10, afterpoint);
		to_int = (int)fpart;
		ft_memset(str, 0, 10); // Initialize the fraction string to all zeros
		i = 0;
		// Convert the fraction part to a string by repeatedly multiplying by 10 and adding the integer part to the result string
		while (to_int > 0 || i < afterpoint)
		{
			str[i++] = (to_int % 10) + '0';
			to_int /= 10;
		}
		// Reverse the fraction string
		j = 0;
		k = i - 1;
		while (j < k)
		{
			temp = str[j];
			str[j] = str[k];
			str[k] = temp;
			j++;
			k--;
		}
		ft_strcat(res, str);
	}
	return (res);
}
