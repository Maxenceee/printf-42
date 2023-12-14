/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:07:51 by mgama             #+#    #+#             */
/*   Updated: 2023/12/14 23:52:09 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

void	ft_putstrprec(char *str, int prec, int *count)
{
	int	c;

	c = 0;
	while (str[c] && c < prec)
		ft_putchar(str[c++]);
	(*count) += c;
}

static void	ft_print_spaces(char *str, int *count, t_flags flags)
{
	if (flags.dot >= 0)
	{
		ft_print_width(flags.dot, ft_strlen(str), 0, count);
		ft_putstrprec(str, flags.dot, count);
	}
	else
	{
		ft_putstrprec(str, ft_strlen(str), count);
	}
}

void	ft_print_str(char *s, int *count, t_flags flags)
{
	int	c;

	c = 0;
	if (!s)
		s = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(s))
		flags.dot = ft_strlen(s);
	if (flags.minus == 1)
		ft_print_spaces(s, count, flags);
	if (flags.dot >= 0)
		ft_print_max_width(flags.width, flags.dot, 0, count);
	else
		ft_print_width(flags.width, ft_strlen(s), 0, count);
	if (flags.minus == 0)
		ft_print_spaces(s, count, flags);
	(*count) += c;
}
