/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:22:22 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/01 10:32:30 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
//int     memcmp(const void *s1, const void *s2, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = s1;
	str2 = s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*int main()
{
	printf("%d\n", ft_memcmp("farah", "Farah", 1));
	printf("%d\n", memcmp("farah", "Farah", 1));
}*/
