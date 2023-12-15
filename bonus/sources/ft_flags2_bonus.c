/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:33:45 by mgama             #+#    #+#             */
/*   Updated: 2023/12/16 00:27:51 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

void	ft_minus_flag(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

void	ft_plus_flag(t_flags *flags)
{
	flags->plus = 1;
	flags->blank = 0;
}

void	ft_digit_flag(char c, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	flags->width = (flags->width * 10) + (c - '0');
}

void	ft_width_flag(va_list *args, t_flags *flags)
{
	flags->star = 1;
	flags->width = va_arg(*args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
}

void	ft_dot_flag(const char *save, int *start,
	t_flags *flags, va_list *args)
{
	(*start)++;
	if (save[*start] == '*')
	{
		flags->dot = va_arg(*args, int);
		(*start)++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(save[*start]))
		{
			flags->dot = (flags->dot * 10) + (save[(*start)++] - '0');
		}
	}
}
