/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 09:59:34 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_elem		*new_list(void)
{
	return (NULL);
}

int			is_empty(t_elem **lst)
{
	if ((*lst) == NULL)
		return (1);
	else
		return (0);
}

t_elem		*init_element(t_elem *element)
{
	element = (t_elem*)malloc(sizeof(t_elem));
	if (element == NULL)
	{
		ft_putendl("MEMORY ALLOCATION ERROR");
		exit(EXIT_FAILURE);
	}
	element->content = NULL;
	element->next = NULL;
	return (element);
}

void		freelst(t_elem **lst)
{
	t_elem		*list;
	t_elem		*tmp;

	list = (*lst);
	while (list)
	{
		tmp = list->next;
		ft_strdel(&(list->content));
		free(list);
		list = tmp;
	}
	(*lst) = NULL;
}
