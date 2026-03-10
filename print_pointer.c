/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzumaki <uzumaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:09:06 by uzumaki           #+#    #+#             */
/*   Updated: 2026/03/11 02:40:48 by uzumaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_long(unsigned long n)
{
	char			c;
	int				len;
	unsigned long	digit;

	digit = n % 16;
	len = 0;
	if (n >= 16)
		len += print_hex_long(n / 16);
	if (digit < 10)
		c = digit + '0';
	else
		c = digit - 10 + 'a';
	len += write(1, &c, 1);
	return (len);
}

int	print_pointer(void *ptr)
{
	unsigned long	adress;
	int				len;

	adress = (unsigned long)ptr;
	len = 0;
	if (ptr == NULL)
		len += write(1, "0x0", 3);
	else
	{
		len += write(1, "0x", 2);
		len += print_hex_long(adress);
	}
	return (len);
}
