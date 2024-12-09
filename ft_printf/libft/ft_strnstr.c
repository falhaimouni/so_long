/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:03:25 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/29 18:58:14 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//char *	strnstr(const char *big, const char *little, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;

	b = (char *)big;
	if (!ft_strlen(little))
		return (b);
	while (*b && len)
	{
		if (len < ft_strlen(little))
			return (NULL);
		if (ft_strncmp(b, little, ft_strlen(little)) == 0)
			return ((char *)b);
		b++;
		len--;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>

int main() {
    const char *haystack = "Hello, this is a sample string.";
    const char *needle = "is";
    size_t len = 3; 
        char *resul = ft_strnstr(haystack, needle, len);
	printf("%s\n",resul);
    return 0;
}*/
