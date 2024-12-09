/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:19:39 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/29 14:50:23 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*int main()
{
	char a[]="";
	char b[]="";
	printf("%d\n" , ft_strncmp(a,b,2));
	printf("%d\n" , strncmp(a,b,2));
}*/
