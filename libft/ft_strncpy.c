/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:02:49 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	if (!len)
		return (dst);
	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i == len)
		return (dst);
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
