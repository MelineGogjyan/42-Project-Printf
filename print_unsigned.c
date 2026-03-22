#include "ft_printf.h"

int	print_unsigned(unsigned int n)
{
	char	c;
	int		len;

	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n >= 10)
	{
		len += print_unsigned(n / 10);
	}
	c = (n % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}
