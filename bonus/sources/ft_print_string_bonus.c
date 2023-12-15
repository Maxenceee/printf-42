/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:07:51 by mgama             #+#    #+#             */
/*   Updated: 2023/12/15 17:07:19 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

void	ft_put_str(char *str, int *count)
{
	size_t	c;

	c = ft_strlen(str);
	write(STDOUT_FILENO, str, c);
	(*count) += c;
}

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
	int		c;
	size_t	len;

	c = 0;
	if (!s)
	{
		if (!(flags.dot == -1 || flags.dot > 6))
			return (ft_print_width(flags.width, 0, 0, count));
		s = "(null)";
	}
	len = ft_strlen(s);
	if (flags.dot >= 0 && (size_t)flags.dot > len)
		flags.dot = len;
	if (flags.minus == 1)
		ft_print_spaces(s, count, flags);
	if (flags.dot >= 0 && flags.width > 0)
		ft_print_width(flags.width, flags.dot, 0, count);
	else if (flags.dot >= 0)
		ft_print_max_width(flags.width, flags.dot, 0, count);
	else
		ft_print_width(flags.width, len, 0, count);
	if (flags.minus == 0)
		ft_print_spaces(s, count, flags);
	(*count) += c;
}
