/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:00:54 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int						i;
	unsigned const char		*ps1;
	unsigned const char		*ps2;

	ps1 = s1;
	ps2 = s2;
	i = 0;
	while (n--)
	{
		if (ps1[i] != ps2[i])
			return ((int)(ps1[i] - ps2[i]));
		i++;
	}
	return (0);
}
