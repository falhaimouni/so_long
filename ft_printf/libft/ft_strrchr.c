/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 08:53:28 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/02 11:39:16 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
//#include <string.h>
char	*ft_strrchr(const char *s, int c)
{
	unsigned char	i;
	int				len;

	len = 0;
	i = (unsigned char)c;
	while (s[len] != '\0')
	{
		len++;
	}
	if (i == '\0')
	{
		return ((char *)(s + len));
	}
	while (len >= 0)
	{
		if (s[len] == i)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
/*int main()
{
	printf("%p\n", (void *)strrchr("farah", '\0'));
    printf("%p\n", (void *)ft_strrchr("farah", '\0'));
    printf("%s\n", strrchr("farah", 'a'));
    printf("%s\n", ft_strrchr("farah", 'a'));
}*/
