/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:13:38 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/08 12:37:38 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointerhex(size_t n)
{
	char	*hex_chars;
	int		count;

	count = 0;
	hex_chars = "0123456789abcdef";
	if (n >= 16)
		count += ft_pointerhex(n / 16);
	ft_putchar_fd(hex_chars[n % 16], 1);
	return (count + 1);
}
