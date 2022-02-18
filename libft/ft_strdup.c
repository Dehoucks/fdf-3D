/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:02:07 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(*ret) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
