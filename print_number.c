/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzumaki <uzumaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:47:44 by uzumaki           #+#    #+#             */
/*   Updated: 2026/03/06 22:18:54 by uzumaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int n)
{
	char	c;
	int		len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		len += print_number(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
	len++;
	return (len);
}
