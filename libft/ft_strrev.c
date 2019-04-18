/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 23:52:56 by kberisha          #+#    #+#             */
/*   Updated: 2017/11/27 00:25:45 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	len;
	char	tmp;

	if (s)
	{
		i = 0;
		len = ft_strlen(s) - 1;
		while (i < len)
		{
			tmp = s[i];
			s[i] = s[len];
			s[len] = tmp;
			i++;
			len--;
		}
	}
	return (s);
}
