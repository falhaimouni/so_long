/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:02:47 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/29 15:05:09 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h> 
//void    *memchr(const void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
/*int main()
{
	printf("%p\n",memchr("farah",'a',5));
	printf("%p\n",ft_memchr("farah",'a',5));
}*/
