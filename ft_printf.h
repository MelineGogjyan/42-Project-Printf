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
