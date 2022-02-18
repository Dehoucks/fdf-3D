/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:03:03 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*ret;
	int		n;
	int		i;

	n = 0;
	i = ft_strlen(str);
	ret = ft_strnew(i--);
	while (i >= 0)
	{
		ret[i] = str[n];
		n++;
		i--;
	}
	return (ret);
}
