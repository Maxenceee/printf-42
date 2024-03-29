/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:33:45 by mgama             #+#    #+#             */
/*   Updated: 2023/12/15 16:57:04 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

# define DIGITS "0123456789abcdef0123456789ABCDEF"

int		ft_printf(const char *fmt, ...);
void	print_type(const char *fmt, va_list *argp, int *count);

void	ft_putchar(char c, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);

void	ft_putnbr(int nb, int *count);
void	ft_putnbr_u(uint32_t nb, int *count);

void	ft_putnbr_base(uint32_t nbr, int capitals, int *count);
void	ft_puthex(uint32_t n, int capitals, int *count);

void	ft_putnbr_base_p(unsigned long int nbr, int capitals, int *count);
void	ft_puthex_p(unsigned long int n, int *count);

size_t	ft_strlen(const char *str);

size_t	ft_nbrsize_l(long int nb);
size_t	ft_nbrsize_ul(unsigned long int nb);

#endif /* ft_printf_h */