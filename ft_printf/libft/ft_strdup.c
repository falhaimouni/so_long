/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:33:37 by falhaimo          #+#    #+#             */
/*   Updated: 2024/08/31 12:00:27 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	i = 0;
	while (s[i])
		i++;
	copy = malloc((i + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*int main()
{
	printf("%s", ft_strdup("Hello world !!"));
}*/
