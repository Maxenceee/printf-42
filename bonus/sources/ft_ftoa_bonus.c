/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:45:47 by mgama             #+#    #+#             */
/*   Updated: 2023/12/15 17:13:58 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <math.h>

#ifndef FTOA_BUFFER_SIZE
# define FTOA_BUFFER_SIZE 30
#endif /* FTOA_BUFFER_SIZE */

/**
 * @brief Convert floating point number to string (original version)
 * 
 * @param n the float number to convert
 * @param afterpoint the floating point precision
 * 
 * 
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
	// Allocate memory for result string and
	// initialize the result string to all zeros
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
	// Convert the integer part to a string by repeatedly dividing
	// by 10 and adding the remainder to the result string
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
		// Convert the fraction part to a string by repeatedly multiplying
		// by 10 and adding the integer part to the result string
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
*/

static void	handle_negative(int *is_negative, int *ipart)
{
	if (*ipart < 0)
	{
		*is_negative = 1;
		*ipart = -*ipart;
	}
}

static void	convert_integer(char *res, int *i, int ipart)
{
	if (ipart == 0)
		res[(*i)++] = '0';
	while (ipart > 0)
	{
		res[(*i)++] = (ipart % 10) + '0';
		ipart /= 10;
	}
}

static void	reverse_string(char *str, int start, int end)
{
	char	temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static char	*convert_fraction(char *res, int i,
	double fpart, int afterpoint)
{
	char	fraction_str[FTOA_BUFFER_SIZE + 1];
	int64_t	to_int;

	ft_strcat(res, ".");
	fpart = (fpart * ft_pow(10, ft_min(afterpoint, FTOA_BUFFER_SIZE))) + 0.5;
	to_int = (int64_t)fpart;
	ft_memset(fraction_str, 0, FTOA_BUFFER_SIZE + 1);
	while (to_int < 0 && i < FTOA_BUFFER_SIZE)
	{
		fpart /= 10;
		fraction_str[(i)++] = '0';
		to_int = (int64_t)fpart;
	}
	while ((to_int > 0 || (i) < afterpoint) && i < FTOA_BUFFER_SIZE)
	{
		fraction_str[(i)++] = (to_int % 10) + '0';
		to_int /= 10;
	}
	reverse_string(fraction_str, 0, (i) - 1);
	return (ft_strjoin(res, fraction_str));
}

char	*ft_ftoa(double n, int afterpoint)
{
	int			ipart;
	double		fpart;
	char		*res;
	int			i;
	int			is_negative;

	ipart = (int)n;
	fpart = n - (float)ipart;
	res = ft_calloc(get_num_len(ipart) + 1 + (n < 0)
			+ (afterpoint != 0), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	is_negative = 0;
	handle_negative(&is_negative, &ipart);
	convert_integer(res, &i, ipart);
	if (is_negative)
		res[i++] = '-';
	reverse_string(res, 0, i - 1);
	if (afterpoint != 0)
		res = convert_fraction(res, 0, fpart, afterpoint);
	return (res);
}
