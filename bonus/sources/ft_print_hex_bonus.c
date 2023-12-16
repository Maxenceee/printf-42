/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:26:50 by mgama             #+#    #+#             */
/*   Updated: 2023/12/16 02:42:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

static void	ft_print_hex_prefix(char *hexa, int lower,
	int *count, t_flags *flags)
{
	if (flags->hex == 1)
	{
		if (lower == 1)
			ft_putstrprec("0x", 2, count);
		else
			ft_putstrprec("0X", 2, count);
		flags->width -= 2;
		flags->hex = 0;
	}
}

static void	ft_print_in_hex_spaces(char *hexa, int lower,
	int *count, t_flags flags)
{
	size_t	len;

	len = ft_strlen(hexa);
	ft_print_hex_prefix(hexa, lower, count, &flags);
	if (flags.dot >= 0)
		ft_print_width(flags.dot - 1, len - 1, 1, count);
	ft_putstrprec(hexa, len, count);
}

static void	ft_print_hex_spaces(char *hexa, int lower,
	int *count, t_flags flags)
{
	size_t	len;

	len = ft_strlen(hexa);
	if (flags.minus == 1)
		ft_print_in_hex_spaces(hexa, lower, count, flags);
	if (flags.zero == 1 && flags.dot == -1)
		ft_print_hex_prefix(hexa, lower, count, &flags);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, (2 * flags.hex), 0, count);
	}
	else
		ft_print_width(flags.width,
			len + (2 * flags.hex), flags.zero, count);
	if (flags.minus == 0)
		ft_print_in_hex_spaces(hexa, lower, count, flags);
}

void	ft_print_hex(uint32_t ui, int lower, int *count, t_flags flags)
{
	char	*hexa;

	ui = (uint32_t)(4294967295 + 1
			+ ui);
	if (flags.dot == 0 && ui == 0)
	{
		ft_print_width(flags.width, 0, 0, count);
		return ;
	}
	if (ui == 0)
		flags.hex = 0;
	hexa = ft_convert_base((uint64_t)ui, 16);
	if (!hexa)
		return ;
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	ft_print_hex_spaces(hexa, lower, count, flags);
	free(hexa);
}
