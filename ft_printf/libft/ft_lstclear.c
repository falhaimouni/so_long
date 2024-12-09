/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:36:00 by falhaimo          #+#    #+#             */
/*   Updated: 2024/09/02 18:11:59 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		if (del)
			del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
