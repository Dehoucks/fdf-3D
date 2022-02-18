/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:00:30 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	t1 = (unsigned char *)dst;
	t2 = (unsigned char *)src;
	while (i < n)
	{
		if ((*t1++ = *t2++) == (unsigned char)c)
			return (t1);
		i++;
	}
	return (NULL);
}
