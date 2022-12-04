/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:33:24 by mgama             #+#    #+#             */
/*   Updated: 2022/12/02 18:02:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_switch_types(const char *fmt, va_list *argp, int *count)
{
	if (*fmt == '%')
		ft_putchar('%', count);
	else if (*fmt == 'c')
		ft_putchar(va_arg(*argp, long), count);
	else if (*fmt == 's')
		ft_putstr_fd(va_arg(*argp, char *), 1, count);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_putnbr(va_arg(*argp, long), count);
	else if (*fmt == 'u')
		ft_putnbr_u(va_arg(*argp, unsigned long), count);
	else if (*fmt == 'x')
		ft_puthex(va_arg(*argp, unsigned int), 0, count);
	else if (*fmt == 'X')
		ft_puthex(va_arg(*argp, unsigned int), 16, count);
	else if (*fmt == 'p')
		ft_puthex_p(va_arg(*argp, unsigned long int), count);
}

void	print_type(const char *fmt, va_list *argp, int *count)
{
	int	i;

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

// int	main(void)
// {	
// 	int i = printf("print %% %c, %s, %d, %i, %u, %x, %X, %p\n", 'c', "azerty", 42, -42, 42, 42, 42, 42);
// 	int j = ft_printf("print %% %c, %s, %d, %i, %u, %x, %X, %p\n", 'c', "azerty", 42, -42, 42, 42, 42, 42);
// 	// int i = printf(" %lp %lp \n", LONG_MIN, LONG_MAX);
// 	// int j = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
// 	// printf("\nprintf %d\nft_printf %d\n", i, j);
// 	// int i = printf(" % s \n", "-");
// 	// int j = ft_printf(" % s \n", "-");
// 	printf("\nprintf %d\nft_printf %d\n", i, j);
// }
