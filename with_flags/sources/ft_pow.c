/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:56:46 by mgama             #+#    #+#             */
/*   Updated: 2022/12/30 00:24:18 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

double	ft_pow(double x, double y)
{
    double	result;
	int		i;

	result = 1.0;
	i = 0;
    while (i++ < y)
        result *= x;
    return (result);
}