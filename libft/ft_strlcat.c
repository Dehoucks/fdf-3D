/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:02:33 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	ret;
	unsigned int	j;

	i = ft_strlen(dst);
	ret = i + ft_strlen(src);
	j = 0;
	if (size < i)
		return (ft_strlen(src) + size);
	if (size > i + 1)
	{
		while (src[j] && j < size - i - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (ret);
}
