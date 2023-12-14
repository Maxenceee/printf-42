/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:47:14 by mgama             #+#    #+#             */
/*   Updated: 2023/12/14 23:52:09 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

void	ft_check_flags(const char *fmt, va_list *argp, t_flags *flags, int *idx)
{
	while (fmt[*idx])
	{
		if (!ft_isdigit(fmt[*idx]) && !ft_is_valid_type(fmt[*idx])
			&& !ft_is_valid_flag(fmt[*idx]))
			break ;
		ft_check_flags_identifiers(fmt, argp, flags, idx);
		if (ft_is_valid_type(fmt[*idx]))
		{
			flags->type = fmt[*idx];
			break ;
		}
		(*idx)++;
	}
}

void	ft_check_flags_identifiers(const char *fmt, va_list *argp,
	t_flags *flags, int *idx)
{
	if (fmt[*idx] == '0' && flags->width == 0 && flags->minus == 0)
		flags->zero = 1;
	if (fmt[*idx] == '.')
		ft_dot_flag(fmt, idx, flags, argp);
	if (fmt[*idx] == '-')
		ft_minus_flag(flags);
	if (fmt[*idx] == '#')
		ft_hex_flag(flags);
	if (fmt[*idx] == '+')
		ft_plus_flag(flags);
	if (fmt[*idx] == ' ')
		ft_blank_flag(flags, fmt, idx);
	if (fmt[*idx] == '*')
		ft_width_flag(argp, flags);
	if (ft_isdigit(fmt[*idx]))
		ft_digit_flag(fmt[*idx], flags);
}

void	ft_hex_flag(t_flags *flags)
{
	flags->hex = 1;
}

void	ft_blank_flag(t_flags *flags, const char *s, int *idx)
{
	while (s[*idx] == ' ')
		(*idx)++;
	if (flags->plus != 1)
		flags->blank = 1;
}
