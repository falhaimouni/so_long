/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 16:05:43 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/08 12:29:39 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_unsigned(n / 10);
	len += ft_putchar_fd(n % 10 + '0', 1);
	return (len);
}

static int	ft_hexalower(unsigned int n)
{
	char	*hex_chars;
	int		count;

	count = 0;
	hex_chars = "0123456789abcdef";
	if (n >= 16)
		count += ft_hexalower(n / 16);
	ft_putchar_fd(hex_chars[n % 16], 1);
	return (count + 1);
}

static int	ft_hexaupper(unsigned int n)
{
	char	*hex_chars;
	int		count;

	count = 0;
	hex_chars = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_hexaupper(n / 16);
	ft_putchar_fd(hex_chars[n % 16], 1);
	return (count + 1);
}

static int	ft_pointer(unsigned long n)
{
	int	count;

	if (n)
	{
		count = 0;
		ft_putchar_fd('0', 1);
		ft_putchar_fd('x', 1);
		count += ft_pointerhex(n);
		return (count + 2);
	}
	return (ft_putstr_fd(("(nil)"), 1));
}

int	ft_conversion(const char c, va_list arg)
{
	if (c == 'd' || c == 'i')
		return (ft_putnum(va_arg(arg, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	else if (c == 'u')
		return (ft_unsigned(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_hexalower(va_arg(arg, unsigned int)));
	else if (c == 'X')
		return (ft_hexaupper(va_arg(arg, unsigned int)));
	else if (c == 'p')
		return (ft_pointer(va_arg(arg, unsigned long)));
	else if (c == '%')
		write(1, "%", 1);
	return (1);
}
