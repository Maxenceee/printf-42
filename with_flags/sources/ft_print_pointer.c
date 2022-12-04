/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:47:22 by mgama             #+#    #+#             */
/*   Updated: 2022/11/21 14:41:55 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_in_pointer_spaces(char *pointer, int *count, t_flags flags)
{
	ft_putstrprec("0x", 2, count);
	if (flags.dot >= 0)
	{
		ft_print_width(flags.dot, ft_strlen(pointer), 1, count);
		ft_putstrprec(pointer, flags.dot, count);
	}
	else
		ft_putstrprec(pointer, ft_strlen(pointer), count);
}

void	ft_print_pointer(unsigned long long ull, int *count, t_flags flags)
{
	char	*pointer;

	if (ull == 0 && flags.dot == 0)
	{
		ft_putstrprec("0x", 2, count);
		ft_print_width(flags.width, 0, 1, count);
		return ;
	}
	pointer = ft_convert_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		ft_print_in_pointer_spaces(pointer, count, flags);
	ft_print_width(flags.width, ft_strlen(pointer) + 2, 0, count);
	if (flags.minus == 0)
		ft_print_in_pointer_spaces(pointer, count, flags);
	free(pointer);
}
