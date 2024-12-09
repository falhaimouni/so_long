/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:31:44 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/01 10:33:16 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1 ||!set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && ft_strchr(set, s1[start]))
		start++;
	while (start <= end && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_strdup(""));
	str = ft_substr(s1, start, end - start + 1);
	if (!str)
		return (NULL);
	return (str);
}
