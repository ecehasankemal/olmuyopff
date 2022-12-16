#include "ft_printf.h"

int	ft_type_control(char c, va_list arg)
{
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 'd' || c == 'i')
		return (ft_int_print(va_arg(arg, int)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_convert(
				va_arg(arg, unsigned long), "0123456789abcdef") + 2);
	}
	else if (c == 'u')
		return (ft_convert(va_arg(arg, unsigned int), "0123456789"));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'x')
		return (ft_convert(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_convert(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		index;
	int		jndex;

	va_start(arg, str);
	index = 0;
	jndex = 0;
	while (str[index] != '\0')
	{
		if (str[index + 1] == '\0' && str[index] == '%')
			write(1, &str[index + 1], 1);
		else if (str[index] == '%')
		{
			jndex += ft_type_control(str[index + 1], arg);
			index++;
		}
		else
			jndex += write(1, &str[index], 1);
		index++;
	}
	va_end(arg);
	return (jndex);
}
