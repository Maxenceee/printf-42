/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_int_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:08:39 by mgama             #+#    #+#             */
/*   Updated: 2023/12/14 23:52:09 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

static void	ft_print_in_u_int_spaces(char *unsi_int, int *count, t_flags flags)
{
	if (flags.dot >= 0)
		ft_print_width(flags.dot - 1, ft_strlen(unsi_int) - 1, 1, count);
	ft_putstrprec(unsi_int, ft_strlen(unsi_int), count);
}

static void	ft_print_u_int_spaces(char *unsi_int, int *count, t_flags flags)
{
	if (flags.minus == 1)
		ft_print_in_u_int_spaces(unsi_int, count, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(unsi_int))
		flags.dot = ft_strlen(unsi_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, 0, count);
	}
	else
		ft_print_width(flags.width,
			ft_strlen(unsi_int), flags.zero, count);
	if (flags.minus == 0)
		ft_print_in_u_int_spaces(unsi_int, count, flags);
}

void	ft_print_u_int(unsigned int unsi, int *count, t_flags flags)
{
	char	*unsi_int;

	unsi = (unsigned int)(4294967295 + 1
			+ unsi);
	if (flags.dot == 0 && unsi == 0)
	{
		ft_print_width(flags.width, 0, 0, count);
		return ;
	}
	unsi_int = ft_u_itoa(unsi);
	if (!unsi)
		return ;
	ft_print_u_int_spaces(unsi_int, count, flags);
	free(unsi_int);
}