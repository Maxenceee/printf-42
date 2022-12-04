/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:47:14 by mgama             #+#    #+#             */
/*   Updated: 2022/11/21 14:41:35 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
