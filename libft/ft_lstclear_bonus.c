/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrootve <sgrootve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:10:31 by sgrootve          #+#    #+#             */
/*   Updated: 2023/10/10 12:55:26 by sgrootve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*old_list;
	t_list	*cur_list;

	if (!del)
		return ;
	cur_list = *lst;
	old_list = NULL;
	while (cur_list != NULL)
	{
		if (old_list != NULL)
		{
			del(old_list->content);
			free(old_list);
		}
		old_list = cur_list;
		cur_list = cur_list->next;
	}
	if (old_list != NULL)
	{
		del(old_list->content);
		free(old_list);
	}
	*lst = NULL;
}
