/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <msaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:11:30 by msaadaou          #+#    #+#             */
/*   Updated: 2025/01/11 20:33:08 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
		ft_lstadd_front(lst, new);
	else
	{
		temp = *lst;
		while (temp)
		{
			if (temp->content < new->content)
				new->index++;
			else
				temp->index++;
			if (temp->next == NULL)
				break ;
			temp = temp->next;
		}
		new->prev = temp;
		temp->next = new;
	}
}
