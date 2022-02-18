/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:00:20 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	if (content)
	{
		if (!(new->content = malloc(sizeof(*content) * content_size)))
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
	}
	new->next = NULL;
	return (new);
}
