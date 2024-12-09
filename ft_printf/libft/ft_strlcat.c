/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:33:37 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/28 13:35:21 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h>
//#include <stddef.h>

//size_t	strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && i < (size - dst_len - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*int main()
{
	char s[] = "farah  ";
	char d[20] = "jehad";
//	printf("%zu\n", ft_strlcat(d,s,3));
//	printf("%zu\n", strlcat(d,s,3));

//	printf("%zu\n", ft_strlcat(d,s,7));
	printf("%zu\n", strlcat(d,s,7));
	


	//strlcat(d,s,3);
//	printf("%s\n", strlcat(d,s,3));
}*/
