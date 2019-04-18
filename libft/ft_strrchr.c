/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:12:23 by kberisha          #+#    #+#             */
/*   Updated: 2017/11/24 15:26:27 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int size;

	size = ft_strlen((char*)s);
	while (s[size] != (char)c && size >= 0)
		size--;
	if (s[size] == (char)c)
		return ((char *)s + size);
	return (NULL);
}
