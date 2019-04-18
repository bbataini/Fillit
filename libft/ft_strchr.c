/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:46:54 by kberisha          #+#    #+#             */
/*   Updated: 2017/11/18 17:23:14 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	ptr = (char*)s;
	i = 0;
	while (ptr[i])
	{
		if (c != '\0')
		{
			if (ptr[i] == c)
				return (ptr + i);
		}
		i++;
	}
	if (c == '\0')
		return (ptr + i);
	return (NULL);
}
