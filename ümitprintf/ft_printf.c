#include "ft_printf.h"

int	ft_numlen(long long n, int base, char *str, int p)
{
	int (count) = 0;
	if (str)
	{
		while (str[count])
			count++;
		return (count);
	}
	else
	{
		if (n <= 0)
			++count;
		while ((unsigned long long)n && p && ++count)
			n = (unsigned long long) n / base;
		while (n && ++count)
			n /= base;
		return (count);
	}
}

char	*bs(long long n, char *table, int p)
{
	int (len) = ft_numlen(n, ft_numlen(0, 0, table, 0), 0, p);
	char *(res) = malloc(sizeof(char) * (len + 1));
	int (tl) = ft_numlen(0, 0, table, 0);
	if (!res)
		return (0);
	res[len] = 0;
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (n && p)
	{
		res[--len] = table[(unsigned long long)n % tl];
		n = (unsigned long long) n / tl;
	}
	while (n)
	{
		if (n > 0)
			res[--len] = table[n % tl];
		else
			res[--len] = table[n % tl * -1];
		n /= tl;
	}
	return (res);
}

int	pc(int c, char *str, int h)
{
	int (count) = 0;
	int (i) = 0;
	if (str != NULL)
	{
		if (h == 1)
			count += pc(0, "0x", 0);
		if (str[i] == '-' && h == 1)
			i++;
		while (str[i])
		{
			write(1, &str[i], 1);
			count++;
			i++;
		}
	}
	else
	{
		if (h)
			return (pc(0, "(null)", 0));
		write(1, &c, 1);
		count = 1;
	}
	return (count);
}

int	ft_printfr(const char *str, va_list args, char *k)
{
	int	count;

	count = 0;
	if (*str == 'd' || *str == 'i')
		count += pc(0, k = bs(va_arg(args, int), NUM, 0), 0);
	else if (*str == 'c')
		count += pc(va_arg(args, int), 0, 0);
	else if (*str == 'p')
		count += pc(0, k = bs((long long)va_arg(args, void *), _H, 1), 1);
	else if (*str == 's')
		count += pc(0, va_arg(args, char *), 2);
	else if (*str == 'u')
		count += pc(0, k = bs(va_arg(args, unsigned int), NUM, 0), 0);
	else if (*str == 'x')
		count += pc(0, k = bs((unsigned int)va_arg(args, int), _H, 0), 0);
	else if (*str == 'X')
		count += pc(0, k = bs((unsigned int)va_arg(args, int), _HU, 0), 0);
	else if (*str == '%')
		count += pc('%', 0, 0);
	if (k != NULL)
		free(k);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	char	*k;

	k = 0;
	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_printfr(str, args, k);
		}
		else
			count += pc(*str, 0, 0);
		str++;
	}
	va_end(args);
	return (count);
}

/*#include <limits.h>
#include <stdio.h>
int main()
{
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
}*/