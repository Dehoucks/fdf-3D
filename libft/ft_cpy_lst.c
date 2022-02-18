/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 09:59:31 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cpy_lst(t_elem **lst_dest, t_elem **lst_src)
{
	t_elem		*head;

	head = (*lst_src);
	while ((*lst_src) != NULL)
	{
		push_elem(lst_dest, (*lst_src)->content);
		(*lst_src) = (*lst_src)->next;
	}
	(*lst_src) = head;
}
