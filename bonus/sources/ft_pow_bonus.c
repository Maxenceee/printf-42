/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:56:46 by mgama             #+#    #+#             */
/*   Updated: 2023/12/15 21:16:03 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

double	ft_pow(double x, double y)
{
	double	result;
	size_t	i;

	result = 1.0;
	i = 0;
	while (i++ < y)
		result *= x;
	return (result);
}
