/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrepel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:00:24 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrepel(t_list **alst, t_list *pnew)
{
	t_list		*list;

	if (!*alst)
		*alst = pnew;
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = pnew;
	}
}
