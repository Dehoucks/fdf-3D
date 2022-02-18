/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:02:58 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	len = ft_strlen(little);
	if (!len)
		return ((char *)big);
	while (big[i] && i < n)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && little[j] && i + j < n)
			j++;
		if (j == len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
