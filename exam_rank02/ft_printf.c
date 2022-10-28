#include <stdarg.h>
#include <unistd.h>

int ft_putstr(char *str)
{
	int len = 0;

	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		len += write (1, str, 1);
		str++;
	}
	return (len);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putnbr(int num)
{
	int len = 0;
	long long n = num;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	len += write(1, &"0123456789"[n % 10], 1);
	return len;
}

int ft_puthex(unsigned int num)
{
	int len = 0;

	if (num >= 16)
		len += ft_puthex(num / 16);
	len += write(1, &"0123456789abcdef"[num % 16], 1);
	return len;
}

int	ft_printf(char *format, ...)
{
	int len;
	va_list ap;

	len = 0;
	va_start (ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				len += ft_putstr(va_arg(ap, char *));
			else if (*format == 'x')
				len += ft_puthex(va_arg(ap, unsigned int));
			else if (*format == 'd')
				len += ft_putnbr(va_arg(ap, int));
			else if (*format == '%')
				len += ft_putchar('%');
		}
		else
		{
			len += ft_putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (len);
}
