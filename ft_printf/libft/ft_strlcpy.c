/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:29:01 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/29 14:51:30 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stddef.h>
#include "libft.h"

//size_t strlcpy(char *dst,const char *src,size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/*int	main()
{
	char c[100];
	printf("%zu\n",ft_strlcpy(c,"farah",0));
	printf("%zu",strlcpy(c,"farah",0));

    return 0;
}*/
