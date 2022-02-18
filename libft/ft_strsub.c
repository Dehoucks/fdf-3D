/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:03:12 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	ret = NULL;
	if (s)
	{
		if ((ret = ft_strnew(len + 1)) == NULL)
			return (NULL);
		i = -1;
		while (++i < len)
			ret[i] = s[start + i];
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
