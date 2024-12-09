/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:22:50 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/26 17:16:17 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
//#include <string.h>
//#include<stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p ;
	size_t	i;

	i = 0;
	p = (char *) s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (p);
}
/*int main()
{
	char c[10];
	printf("%p",ft_memset(c,1,3));
	printf("\n");
	printf("%p",memset(c,1,3));
}*/
