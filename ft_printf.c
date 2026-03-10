/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzumaki <uzumaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:16:40 by uzumaki           #+#    #+#             */
/*   Updated: 2026/03/11 02:25:00 by uzumaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char c, va_list args)
{
	if (c == 'c')
		return (print_char((va_arg(args, int))));
	if (c == 's')
		return (print_string((va_arg(args, char *))));
	if (c == 'd' || c == 'i')
		return (print_number(va_arg(args, int)));
	if (c == 'p')
		return (print_pointer(va_arg(args, void *)));
	if (c == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (print_hex(va_arg(args, unsigned int), c));
	if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += handle_format(format[i + 1], args);
			i++;
		}
		else
			len += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	main(void)
{
	int len1, len2;
	// Char
	len1 = ft_printf("ft_printf -> Hello %c\n", 'A');
	len2 = printf("printf -> Hello %c\n", 'A');
	ft_printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
	// Strings
	len1 = ft_printf("ft_printf -> String: %s\n", "Test");
	len2 = printf("printf -> String: %s\n", "Test");
	ft_printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
	// Numbers
	len1 = ft_printf("ft_printf -> Number: %d %i\n", 42, -42);
	len2 = printf("printf -> Number: %d %i\n", 42, -42);
	ft_printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
	// Pointer
	len1 = ft_printf("ft_printf -> Pointer: %p\n", "10");
	len2 = printf("printf -> Pointer: %p\n", "10");
	ft_printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
	// Unsigned int
	len1 = ft_printf("ft_printf -> Unsigned: %u\n", 3000000000U);
	len2 = printf("printf -> Unsigned: %u\n", 3000000000U);
	ft_printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
	// Hex lower
	len1 = ft_printf("ft_printf -> Hex lower: %x\n", 255);
	len2 = printf("printf -> Hex lower: %x\n", 255);
	ft_printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
	// Hex upper
	len1 = ft_printf("ft_printf -> Hex upper: %X\n", 255);
	len2 = printf("printf -> Hex upper: %X\n", 255);
	ft_printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
	// %
	len1 = ft_printf("ft_printf -> Percent: %%\n");
	len2 = printf("printf -> Percent: %%\n");
	ft_printf("ft_printf len: %d, printf len: %d\n\n", len1, len2);
	return (0);
}
