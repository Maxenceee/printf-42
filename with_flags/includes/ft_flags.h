/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:16:35 by mgama             #+#    #+#             */
/*   Updated: 2022/12/09 17:27:15 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_H
# define FT_FLAGS_H

# include "ft_printf.h"

void	ft_check_flags(const char *fmt, va_list *argp,
			t_flags *flags, int *idx);
void	ft_check_flags_identifiers(const char *fmt, va_list *argp,
			t_flags *flags, int *idx);
void	ft_hex_flag(t_flags *flags);
void	ft_blank_flag(t_flags *flags, const char *s, int *idx);
void	ft_minus_flag(t_flags *flags);
void	ft_digit_flag(char c, t_flags *flags);
void	ft_width_flag(va_list *args, t_flags *flags);
void	ft_dot_flag(const char *save, int *start,
			t_flags *flags, va_list *args);
void	ft_plus_flag(t_flags *flags);

#endif /* ft_flags_h */