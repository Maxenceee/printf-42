/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:17:43 by mgama             #+#    #+#             */
/*   Updated: 2023/12/15 19:30:58 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

static void	ft_print_in_int_spaces(char *d_i, int save_i,
	int *count, t_flags flags)
{
	size_t	len;

	len = ft_strlen(d_i);
	if (save_i < 0 && flags.dot >= 0)
		ft_putchar_c('-', count);
	if (flags.dot >= 0)
		ft_print_width(flags.dot - 1, len - 1, 1, count);
	if (!(flags.dot == 0 && save_i == 0))
		ft_putstrprec(d_i, len, count);
}

static void	ft_print_int_spaces(char *d_i, int save_i,
	int *count, t_flags flags)
{
	size_t	len;

	len = ft_strlen(d_i);
	if (flags.minus == 1)
		ft_print_in_int_spaces(d_i, save_i, count, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < len && save_i > 0)
		flags.dot = len;
	if (flags.dot >= 0)
		ft_print_width(flags.width, len, 0, count);
	else
		ft_print_width(flags.width, len, flags.zero, count);
	if (save_i >= 0 && flags.plus == 1)
		ft_putstrprec("+", 1, count);
	else if (save_i >= 0 && flags.blank == 1)
		ft_putstrprec(" ", 1, count);
	if (flags.minus == 0)
		ft_print_in_int_spaces(d_i, save_i, count, flags);
}

static void	ft_print_int_flags(t_flags *flags, long int *li, int *count)
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
		flags->width--;
	}
	else if (*li >= 0 && flags->blank == 1)
	{
		flags->width--;
	}
}

void	ft_print_int(int i, int *count, t_flags flags)
{
	char		*d_i;
	long int	li;

	li = i;
	ft_print_int_flags(&flags, &li, count);
	d_i = ft_itoa(li);
	if (!d_i)
		return ;
	ft_print_int_spaces(d_i, i, count, flags);
	free(d_i);
}
