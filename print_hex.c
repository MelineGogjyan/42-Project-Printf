#include "ft_printf.h"

int	print_hex(unsigned int n, char format)
{
	char	c;
	int		len;
	int		digit;

	digit = n % 16;
	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 16)
		len += print_hex(n / 16, format);
	if (digit < 10)
		c = digit + '0';
	else if (format == 'x')
		c = digit - 10 + 'a';
	else if (format == 'X')
		c = digit - 10 + 'A';
	len += write(1, &c, 1);
	return (len);
}
