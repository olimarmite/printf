#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

#define CHR_PATTERN "c"
#define STR_PATTERN "s"
#define PTR_PATTERN "p"
#define DEC_PATTERN "d"
#define INT_PATTERN "i"
#define U_INT_PATTERN "u"
#define HEX_PATTERN "x"
#define HEX_UC_PATTERN "X"
#define PERCENT_PATTERN "%"
#define HEX_UC_ALPHABET "0123456789ABCDEF"
#define HEX_LC_ALPHABET "0123456789abcdef"
#define DEC_ALPHABET "0123456789"

int	ft_putstr(char *s)
{
	size_t	len;

	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	while (s[len] != 0)
		len++;
	write(1, s, len);
	return (len);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_base(long n, long base, const char *base_alphabet)
{
	int	out;

	out = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
		out += 1;
	}
	if (n < base)
	{
		ft_putchar(base_alphabet[n % base]);
		out += 1;
	}
	else
	{
		out = 1 + out + ft_putnbr_base(n / base, base, base_alphabet);
		ft_putchar(base_alphabet[n % base]);
	}
	return (out);
}

int	ft_put_u_nbr_base(unsigned long n, unsigned long base,
		const char *base_alphabet)
{
	int	out;

	out = 0;
	if (n < base)
	{
		ft_putchar(base_alphabet[n % base]);
		out += 1;
	}
	else
	{
		out = 1 + out + ft_putnbr_base(n / base, base, base_alphabet);
		ft_putchar(base_alphabet[n % base]);
	}
	return (out);
}

//return 0 : match
int	pattern_matcher(char const *str, const char *pattern)
{
	if (pattern == NULL || str == NULL)
		return (1);
	while (*pattern == *str && *pattern != 0)
	{
		pattern++;
		str++;
	}
	return (*pattern != 0);
}

int	null_handler(void *value, char *null_str, size_t *letter_count)
{
	if (value == 0)
	{
		*letter_count += ft_putstr(null_str);
		return (1);
	}
	return (0);
}

int	number_handler(const char *str, int *letter_count, va_list *argprt, int *i)
{
	if (pattern_matcher(str + *i, DEC_PATTERN) == 0 ||
		pattern_matcher(str + *i, INT_PATTERN) == 0)
		*letter_count += ft_putnbr_base(va_arg(*argprt, int), 10, DEC_ALPHABET);
	else if (pattern_matcher(str + *i, HEX_UC_PATTERN) == 0)
		*letter_count += ft_putnbr_base(va_arg(*argprt, unsigned int), 16,
				HEX_UC_ALPHABET);
	else if (pattern_matcher(str + *i, HEX_UC_PATTERN) == 0)
		*letter_count += ft_putnbr_base(va_arg(*argprt, unsigned int), 16,
				HEX_UC_ALPHABET);
	else if (pattern_matcher(str + *i, HEX_PATTERN) == 0)
		*letter_count += ft_putnbr_base(va_arg(*argprt, unsigned int), 16,
				HEX_LC_ALPHABET);
	else if (pattern_matcher(str + *i, U_INT_PATTERN) == 0)
		*letter_count += ft_putnbr_base(va_arg(*argprt, unsigned int), 10,
				DEC_ALPHABET);
	else
		return (0);
	return (1);
}

int	text_handler(const char *str, int *letter_count, va_list *argprt, int *i)
{
	if (pattern_matcher(str + *i, CHR_PATTERN) == 0)
		*letter_count += ft_putchar(va_arg(*argprt, int));
	else if (pattern_matcher(str + *i, STR_PATTERN) == 0)
		*letter_count += ft_putstr(va_arg(*argprt, char *));
	else
		return (0);
	return (1);
}

//return -1 if err
int	flag_handler(const char *str, int *letter_count, va_list *argprt, int *i)
{
	void	*current_arg;

	if ((text_handler(str, letter_count, argprt, i) || number_handler(str,
				letter_count, argprt, i) || pattern_matcher(str + *i,
				PTR_PATTERN)) == false)
		else if (pattern_matcher(str + *i, PTR_PATTERN) == 0)
		{
			current_arg = (void *)va_arg(*argprt, unsigned long);
			if (null_handler(current_arg, "(nil)", letter_count) == 0)
			{
				*letter_count += ft_putstr("0x");
				*letter_count += ft_put_u_nbr_base((unsigned long)current_arg,
						16, HEX_LC_ALPHABET);
			}
		}
	else if (pattern_matcher(str + *i, PERCENT_PATTERN) == 0)
		*letter_count += ft_putchar('%');
	else if (str[*i] == '\0')
		return (-1);
	else
	{
		*letter_count += ft_putchar('%');
		return (0);
	}
	(*i)++;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	letter_count;
	va_list	argprt;

	va_start(argprt, str);
	i = 0;
	letter_count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (flag_handler(str, &letter_count, &argprt, &i) == -1)
				return (-1);
		}
		else
		{
			letter_count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(argprt);
	return (letter_count);
}
