/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:33:24 by mgama             #+#    #+#             */
/*   Updated: 2023/12/16 01:28:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_switch_types(const char *fmt, va_list *argp, int *count)
{
	if (*fmt == '%')
		ft_putchar('%', count);
	else if (*fmt == 'c')
		ft_putchar(va_arg(*argp, long), count);
	else if (*fmt == 's')
		ft_putstr_fd(va_arg(*argp, char *), STDOUT_FILENO, count);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr(va_arg(*argp, long), count);
	else if (*fmt == 'u')
		ft_putnbr_u(va_arg(*argp, unsigned long), count);
	else if (*fmt == 'x')
		ft_puthex(va_arg(*argp, uint32_t), 0, count);
	else if (*fmt == 'X')
		ft_puthex(va_arg(*argp, uint32_t), 16, count);
	else if (*fmt == 'p')
		ft_puthex_p(va_arg(*argp, unsigned long int), count);
}

void	print_type(const char *fmt, va_list *argp, int *count)
{
	size_t	i;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
		{
			ft_putchar(fmt[i++], count);
			continue ;
		}
		i++;
		ft_switch_types(fmt + i, argp, count);
		if (*count == -1)
			return ;
		i++;
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	listp;
	int		count;

	count = 0;
	va_start(listp, fmt);
	print_type(fmt, &listp, &count);
	va_end(listp);
	return (count);
}
