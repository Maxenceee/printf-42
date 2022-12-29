/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:44:18 by mgama             #+#    #+#             */
/*   Updated: 2022/12/29 15:51:08 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_flags.h"

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

static void	ft_print_in_float_spaces(char *d_i, double save_f,
	int *count, t_flags flags)
{
	if (save_f < 0 && flags.dot >= 0)
		ft_putchar_c('-', count);
	ft_putstrprec(d_i, ft_strlen(d_i), count);
	if (flags.dot >= 0)
		ft_print_max_width(flags.dot,
			(int)ft_strlen_floating_part(d_i) - 1, 1, count);
}

static void	ft_print_float_spaces(char *d_i, double save_f,
	int *count, t_flags flags)
{
	if (flags.minus == 1)
		ft_print_in_float_spaces(d_i, save_f, count, flags);
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
		ft_print_in_float_spaces(d_i, save_f, count, flags);
}

static void	ft_print_float_flags(t_flags *flags, double *li, int *count)
{
	if (*li < 0 && (flags->dot >= 0 || flags->zero == 1))
	{
		if (flags->zero == 1 && flags->dot == -1)
			ft_putstrprec("-", 1, count);
		(*li) *= -1;
		flags->zero = 1;
		flags->width--;
	}
	else if (*li >= 0 && flags->plus == 1)
	{
		ft_putstrprec("+", 1, count);
		flags->width--;
	}
	else if (*li >= 0 && flags->blank == 1)
	{
		ft_putstrprec(" ", 1, count);
		flags->width--;
	}
}

void	ft_print_float(double i, int *count, t_flags flags)
{
	char	*d_i;
	double	li;
	int		max;

	li = i;
	max = 6;
	if (flags.dot == 0 && li == 0)
	{
		ft_print_width(flags.width, 0, 0, count);
		return ;
	}
	if (flags.dot >= 0)
		max = flags.dot;
	ft_print_float_flags(&flags, &li, count);
	d_i = ft_ftoa(li, max);
	ft_print_float_spaces(d_i, i, count, flags);
	free(d_i);
}
