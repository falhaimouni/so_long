/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:41:53 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/02 10:21:29 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h> 
char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_char;
	int				i;

	i = 0;
	c_char = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c_char)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == 0 && c_char != '\0')
		return (NULL);
	return ((char *)s + i);
}
/*int main()
{
	printf("%p\n",strchr("farah",'\0'));
	printf("%p\n",ft_strchr("farah",'\0'));
}*/
