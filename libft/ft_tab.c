/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:03:16 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**list_to_tab(t_elem **lst)
{
	int			i;
	size_t		j;
	char		**tab;
	t_elem		*head;

	i = 0;
	j = 0;
	tab = NULL;
	head = (*lst);
	while ((*lst) != NULL)
	{
		j++;
		(*lst) = (*lst)->next;
	}
	(*lst) = head;
	if (!(tab = ft_memalloc(sizeof(*tab) * (j + 1))))
		exit(EXIT_FAILURE);
	while ((*lst) != NULL)
	{
		tab[i] = (*lst)->content;
		(*lst) = (*lst)->next;
		i++;
	}
	(*lst) = head;
	return (tab);
}

void	tab_to_list(t_elem **lst, char **tab)
{
	int		i;

	i = 0;
	while (tab[i] && tab[i][0] != '\0')
	{
		push_elem(lst, tab[i]);
		i++;
	}
}

void	supp_elem_tab(char **tab, int value)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] && tab[i][0] != '\0')
		i++;
	if (value >= i)
		return ;
	else
	{
		while (j < i)
		{
			tab[j] = tab[j + 1];
			j++;
		}
	}
	return ;
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] != NULL)
		{
			ft_strdel(&(tab[i]));
			i++;
		}
		else
			i++;
	}
	free(tab);
	tab = NULL;
}
