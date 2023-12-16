/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:17:43 by mgama             #+#    #+#             */
/*   Updated: 2023/12/16 00:55:26 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

static void	ft_print_in_int_spaces(char *d_i, int save_i,
	int *count, t_flags flags)
{
	if (save_i < 0 && flags.dot >= 0)
		ft_putchar_c('-', count);
	else if (save_i >= 0 && flags.plus == 1)
		ft_putchar_c('+', count);
	else if (save_i >= 0 && flags.blank == 1)
		ft_putchar_c(' ', count);
	if (flags.dot >= 0)
		ft_print_width(flags.dot - 1, ft_strlen(d_i) - 1, 1, count);
	ft_putstrprec(d_i, ft_strlen(d_i), count);
}

static void	ft_print_int_spaces(char *d_i, int save_i,
	int *count, t_flags flags)
{
	if (flags.minus == 1)
		ft_print_in_int_spaces(d_i, save_i, count, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, 0, count);
	}
	else
		ft_print_width(flags.width, ft_strlen(d_i), flags.zero, count);
	if (flags.minus == 0)
		ft_print_in_int_spaces(d_i, save_i, count, flags);
}

static void	ft_print_int_flags(t_flags *flags, long int *li, int *count)
{
	if (*li >= 0 && (flags->plus == 1 || flags->blank == 1))
		flags->width--;
	if (!(flags->dot >= 0 || flags->zero == 1))
		return ;
	if (*li < 0)
	{
		if (flags->zero == 1 && flags->dot == -1)
			ft_putstrprec("-", 1, count);
		(*li) *= -1;
		flags->zero = 1;
		flags->width--;
	}
	else if (*li >= 0 && flags->plus == 1 && flags->zero == 1 && flags->dot == -1)
	{
		ft_putstrprec("+", 1, count);
		flags->plus = 0;
	}
	else if (*li >= 0 && flags->blank == 1 && flags->zero == 1 && flags->dot == -1)
	{
		ft_putstrprec(" ", 1, count);
		flags->blank = 0;
	}
}

void	ft_print_int(int i, int *count, t_flags flags)
{
	char		*d_i;
	long int	li;

	li = i;
	ft_print_int_flags(&flags, &li, count);
	if (li == 0 && flags.dot == 0)
		d_i = ft_calloc(1, sizeof(char));
	else
		d_i = ft_itoa(li);
	if (!d_i)
		return ;
	ft_print_int_spaces(d_i, i, count, flags);
	free(d_i);
}
