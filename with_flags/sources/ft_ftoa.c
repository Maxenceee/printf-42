/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:45:47 by mgama             #+#    #+#             */
/*   Updated: 2023/04/21 22:17:11 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_ftoa(double n, int afterpoint)
{
	int					ipart;
	double				fpart;
	char				*res;
	char				temp;
	int					i;
	int					k;
	long long int		to_int;
	char				str[30];
	int					is_negative;

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
	k = i - 1;
	i = 0;
	while (i < k)
	{
		temp = res[i];
		res[i] = res[k];
		res[k] = temp;
		i++;
		k--;
	}
	// Check for display option after point
	if (afterpoint != 0)
	{
		// Add dot
		ft_strcat(res, ".");
		// Get the value of fraction part upto given of points after dot.
		fpart = fpart * ft_pow(10, afterpoint);
		to_int = (long long int)fpart;
		ft_memset(str, 0, 30); // Initialize the fraction string to all zeros
		i = 0;
		// If to_int can't fit in long long int cast, reduce it until it can
		while (to_int < 0)
		{
			fpart /= 10;
			str[i++] = '0';
			to_int = (long long int)fpart;
		}
		// Convert the fraction part to a string by repeatedly multiplying by 10 and adding the integer part to the result string
		while (to_int > 0 || i < afterpoint)
		{
			str[i] = (to_int % 10) + '0';
			to_int /= 10;
			i++;
		}
		// Reverse the fraction string
		k = i - 1;
		i = 0;
		while (i < k)
		{
			temp = str[i];
			str[i] = str[k];
			str[k] = temp;
			i++;
			k--;
		}
		ft_strcat(res, str);
	}
	return (res);
}
