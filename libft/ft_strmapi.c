/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:12:53 by kberisha          #+#    #+#             */
/*   Updated: 2017/11/26 13:46:54 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = NULL;
	if (s)
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		if (s)
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
		}
		str[i] = '\0';
	}
	return (str);
}
