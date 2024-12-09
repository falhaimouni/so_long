/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:00:29 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/29 14:13:57 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	d = (char *) dest;
	s = (const char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s || d >= (s + n))
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
		{
			*(--d) = *(--s);
		}
	}
	return (dest);
}
/*int main()
{

	char src[] = "Hello, World!";
  	  char dest[]="farah alhaimouni";

   
   printf("%s\n", (char *)ft_memmove(dest, src, 5));
   printf("%s\n", (char *)memcpy(dest, src, 5));
  printf("hi\n");

}*/
