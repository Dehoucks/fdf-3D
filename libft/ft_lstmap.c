/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:00:17 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*list;
	t_list		*new;
	t_list		*new_list;

	list = lst;
	new_list = NULL;
	while (list)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new = f(list);
		ft_lstrepel(&new_list, new);
		list = list->next;
	}
	return (new_list);
}
