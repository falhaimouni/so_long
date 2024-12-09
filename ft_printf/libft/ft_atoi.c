/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:29:44 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/29 16:12:28 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
//size_t	ft_strlen(const char *s);
int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (nptr[i] == 32 || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * neg);
}
/*int	main()
{
	printf("%d\n", ft_atoi("12345678901234567890"));
	printf("%d\n", atoi("12345678901234567890"));
}*/
