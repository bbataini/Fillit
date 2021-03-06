/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:18:15 by kberisha          #+#    #+#             */
/*   Updated: 2017/11/20 02:17:03 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] && s2[i]) && (i < n))
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if ((s1[i] || s2[i]) && i != n)
			return (0);
		return (1);
	}
	return (0);
}
