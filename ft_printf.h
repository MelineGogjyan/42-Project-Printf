/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzumaki <uzumaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:22:47 by uzumaki           #+#    #+#             */
/*   Updated: 2026/03/11 00:41:41 by uzumaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	handle_format(char c, va_list args);
int	print_char(char c);
int	print_string(char *s);
int	print_number(int n);
int	print_unsigned(unsigned int n);
int	print_hex(unsigned int n, char format);
int	print_pointer(void *ptr);

#endif
