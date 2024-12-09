/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:56:33 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/09 08:06:20 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *c, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	va_start(arg, c);
	count = 0;
	while (c[i] != '\0')
	{
		if (c[i] == '%')
		{
			i++;
			count += ft_conversion(c[i], arg);
		}
		else
			count += ft_putchar_fd(c[i], 1);
		i++;
	}
	va_end(arg);
	return (count);
}
