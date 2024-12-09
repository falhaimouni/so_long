/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:22:50 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/02 18:13:01 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst ||!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}
