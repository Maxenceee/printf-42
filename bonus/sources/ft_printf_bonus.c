/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:33:24 by mgama             #+#    #+#             */
/*   Updated: 2023/12/15 16:50:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_flags_bonus.h"
#include "ft_printf_bonus.h"

static t_flags	ft_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	flags.plus = 0;
	flags.hex = 0;
	flags.blank = 0;
	return (flags);
}

static void	ft_switch_types(int type, va_list *argp, int *count, t_flags flags)
{
	if (type == '%')
		ft_putchar_c('%', count);
	else if (type == 'c')
		ft_print_char(va_arg(*argp, long), count, flags);
	else if (type == 's')
		ft_print_str(va_arg(*argp, char *), count, flags);
	else if (type == 'd' || type == 'i')
		ft_print_int(va_arg(*argp, long), count, flags);
	else if (type == 'f')
		ft_print_float(va_arg(*argp, double), count, flags);
	else if (type == 'u')
		ft_print_u_int(va_arg(*argp, unsigned long), count, flags);
	else if (type == 'x')
		ft_print_hex(va_arg(*argp, uint32_t), 1, count, flags);
	else if (type == 'X')
		ft_print_hex(va_arg(*argp, uint32_t), 0, count, flags);
	else if (type == 'p')
		ft_print_pointer(va_arg(*argp, unsigned long int), count, flags);
}

static void	ft_print_type(const char *fmt, va_list *argp, int *count)
{
	int		i;
	t_flags	flags;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
		{
			ft_putchar_c(fmt[i++], count);
			continue ;
		}
		flags = ft_flags();
		i++;
		ft_check_flags(fmt, argp, &flags, &i);
		if (ft_is_valid_type(fmt[i]))
			ft_switch_types(flags.type, argp, count, flags);
		else
			ft_putchar_c(fmt[i], count);
		i++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	listp;
	int		count;

	count = 0;
	va_start(listp, fmt);
	ft_print_type(fmt, &listp, &count);
	va_end(listp);
	return (count);
}
