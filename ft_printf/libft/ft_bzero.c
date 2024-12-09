/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:18:25 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/26 18:44:42 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	char	*p ;
	size_t	i;

	p = (char *) s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*int main() {
    char buffer[10] = "023456789";

    printf("Before bzero: %s\n", buffer);
    ft_bzero(buffer+2, 6);

    printf("After bzero: %s\n", buffer);

	
	char c[10] = "023456789";
    printf("Before bzero: %s\n", c);
    bzero(c+2, 5);

    printf("After bzero: %s\n", c);


    return 0;
}*/
