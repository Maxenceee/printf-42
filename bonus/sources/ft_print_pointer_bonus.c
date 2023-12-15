/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:47:22 by mgama             #+#    #+#             */
/*   Updated: 2023/12/15 17:49:35 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

static void	ft_print_in_pointer_spaces(char *pointer, uint64_t or,
	int *count, t_flags flags)
{
	size_t	len;

	len = ft_strlen(pointer);
	ft_putstrprec("0x", 2, count);
	if (flags.dot >= 0)
	{
		ft_print_width(flags.dot, len, 1, count);
		ft_putstrprec(pointer, flags.dot, count);
	}
	else
		ft_putstrprec(pointer, len, count);
}

#ifdef __APPLE__

void	ft_print_pointer(uint64_t ull, int *count, t_flags flags)
{
	char	*pointer;
	size_t	len;

	if (ull == 0 && flags.dot == 0)
	{
		ft_putstrprec("0x", 2, count);
		ft_print_width(flags.width, 0, 1, count);
		return ;
	}
	pointer = ft_convert_base(ull, 16);
	if (!pointer)
		return ;
	len = ft_strlen(pointer);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < len)
		flags.dot = len;
	if (flags.minus == 1)
		ft_print_in_pointer_spaces(pointer, ull, count, flags);
	ft_print_width(flags.width, len + 2, 0, count);
	if (flags.minus == 0)
		ft_print_in_pointer_spaces(pointer, ull, count, flags);
	free(pointer);
}

#else

void	ft_print_pointer(uint64_t ull, int *count, t_flags flags)
{
	char	*pointer;
	size_t	len;

	if (ull == 0 && flags.dot == 0)
	{
		ft_putstrprec("0x", 2, count);
		ft_print_width(flags.width, 0, 1, count);
		return ;
	}
	if (ull)
		pointer = ft_convert_base(ull, 16);
	else
		pointer = ft_strdup("(nil)");
	if (!pointer)
		return ;
	len = ft_strlen(pointer);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < len)
		flags.dot = len;
	if (flags.minus == 1)
		ft_print_in_pointer_spaces(pointer, ull, count, flags);
	ft_print_width(flags.width, len + (2 * (ull > 0)), 0, count);
	if (flags.minus == 0)
		ft_print_in_pointer_spaces(pointer, ull, count, flags);
	free(pointer);
}

#endif /* __APPLE__ */