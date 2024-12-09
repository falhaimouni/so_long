/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:59:31 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/07 16:14:36 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*init(int *min, int *len, int n, int *sign)
{
	*min = 0;
	*len = lenst(n);
	*sign = 0;
	return (ft_calloc((*len + 1), sizeof(char)));
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*final;
	int		i;
	int		min;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	final = init(&min, &i, n, &sign);
	if (!final)
		return (NULL);
	final[0] = '0';
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	while (i > 0)
	{
		final[i - 1] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	if (sign == -1)
		final[i] = '-';
	return (final);
}
// int    main(void)
// {
//     printf("%s", ft_itoa(-654654));
// }
