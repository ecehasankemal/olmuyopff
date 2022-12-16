#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int (count) = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_numsize(size_t data, char *base)
{
	int (res) = 0;
	int (intbase) = 0;
	while (base[intbase])
		intbase++;
	while (data)
	{
		res++;
		data = data / intbase;
	}
	return (res);
}

int	ft_int_print(int content)
{
	if (content < 0)
	{
		ft_putchar('-');
		if (content == -2147483648)
			return (ft_convert(2147483648, "0123456789") + 1);
		content *= -1;
		return (ft_convert(content, "0123456789") + 1);
	}
	return (ft_convert(content, "0123456789"));
}

int	ft_convert(size_t data, char *base)
{
	int (size) = ft_numsize(data, base);
	//char *(str) = (char *)malloc(sizeof(char) * (size + 1));
	char *(str) = (char *)malloc(sizeof(char) * 50);
	int (intbase);
	int (res) = 0;
	if (str == NULL)
		return (0);
	while (base[intbase])
		intbase++;
	while (data > 0)
	{
		str[size - 1] = base[data % intbase];
		data /= intbase;
		size--;
	}
	while (str[res])
		res++;
	ft_putstr(str);
	free(str);
	return (res);
}
