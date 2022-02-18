/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:09 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 09:58:12 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	freelst(t_elem **lst)
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
