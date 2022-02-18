/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robindehouck <robindehouck@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:58:21 by robindehouc       #+#    #+#             */
/*   Updated: 2022/02/18 10:02:10 by robindehouc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
