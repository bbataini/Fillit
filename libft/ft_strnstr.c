/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:49:49 by kberisha          #+#    #+#             */
/*   Updated: 2017/11/24 20:45:01 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (hay[i] && i < len)
	{
		if (hay[i] == needle[j])
		{
			while (hay[i] == needle[j] && i < len && needle[j])
			{
				i++;
				j++;
			}
		}
		if (needle[j] == '\0')
			return ((char*)hay + i - j);
		else
			i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
