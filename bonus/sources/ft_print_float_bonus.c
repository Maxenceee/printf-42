/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:44:18 by mgama             #+#    #+#             */
/*   Updated: 2023/12/16 02:38:23 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

static size_t	ft_strlen_floating_part(const char *str)
{
	size_t	count;
	int		counting;

	count = 0;
	counting = 0;
	while (*str != '\0')
	{
		str++;
		if (counting)
			count++;
		if (*str == '.')
			counting = 1;
	}
	return (count);
}

static void	ft_print_in_float_spaces(char *d_f, double save_f,
	int *count, t_flags flags)
{
	if (save_f < 0 && flags.dot >= 0)
		ft_putchar_c('-', count);
	else if (save_f >= 0 && flags.plus == 1)
		ft_putchar_c('+', count);
	else if (save_f >= 0 && flags.blank == 1)
		ft_putchar_c(' ', count);
	if (flags.dot >= 0)
		ft_print_max_width(flags.dot,
			(int)ft_strlen_floating_part(d_f) - 1, 1, count);
	ft_putstrprec(d_f, ft_strlen(d_f), count);
}

static void	ft_print_float_spaces(char *d_f, double save_f,
	int *count, t_flags flags)
{
	size_t	len;

	len = ft_strlen(d_f);
	if (flags.minus == 1)
		ft_print_in_float_spaces(d_f, save_f, count, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, flags.zero, count);
	}
	else
		ft_print_width(flags.width, len, flags.zero, count);
	if (flags.minus == 0)
		ft_print_in_float_spaces(d_f, save_f, count, flags);
}

static void	ft_print_float_flags(t_flags *flags, double *li, int *count)
{
	if (*li >= 0 && (flags->plus == 1 || flags->blank == 1))
		flags->width--;
	if (*li < 0 && flags->zero == 1)
	{
		if (flags->zero == 1)
			ft_putstrprec("-", 1, count);
		(*li) *= -1;
		flags->zero = 1;
		flags->width--;
		flags->plus = 0;
	}
	else if (*li >= 0 && flags->plus == 1 && flags->zero == 1)
	{
		ft_putstrprec("+", 1, count);
		flags->plus = 0;
	}
	else if (*li >= 0 && flags->blank == 1 && flags->zero == 1)
	{
		ft_putstrprec(" ", 1, count);
		flags->blank = 0;
	}
	else if (*li < 0)
		flags->width--;
}

void	ft_print_float(double i, int *count, t_flags flags)
{
	char	*d_f;
	double	li;
	int		max;

	li = i;
	max = 6;
	if (flags.dot >= 0)
		max = flags.dot;
	ft_print_float_flags(&flags, &li, count);
	if (i < 0)
		i = -i;
	d_f = ft_ftoa(i, max);
	if (!d_f)
		return ;
	ft_print_float_spaces(d_f, li, count, flags);
	free(d_f);
}
