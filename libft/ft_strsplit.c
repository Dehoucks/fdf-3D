/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:03:07 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_lenword(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		nbrword;

	i = 0;
	nbrword = ft_countword(s, c);
	if (!s)
		return (NULL);
	if (!(ret = (char **)malloc(sizeof(*ret) * (nbrword + 1))))
		return (NULL);
	while (nbrword--)
	{
		while (*s == c && *s)
			s++;
		ret[i] = ft_strsub(s, 0, ft_lenword(s, c));
		if (ret[i] == NULL)
		{
			ft_memdel((void **)ret);
			return (NULL);
		}
		s += ft_lenword(s, c);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
