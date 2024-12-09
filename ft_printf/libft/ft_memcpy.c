/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:23:13 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/29 14:04:01 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	size_t		i;
	char		*d;

	i = 0;
	d = (char *) dest;
	s = (const char *)src;
	if (!d && !s)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*int	main()
{
	 char src[] = "Hello, World!";
    char dest[50];

   
   printf("%p\n", ft_memcpy(dest, src, strlen(src) + 1));
//   printf("%p\n", memcpy(dest, src, strlen(src) + 1));
    printf("Source: %s\n", src);
    printf("Destination: %s\n", dest);


}*/
