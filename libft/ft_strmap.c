/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:07:45 by kberisha          #+#    #+#             */
/*   Updated: 2017/11/22 17:45:16 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	char	*ss;

	i = 0;
	ss = (char*)s;
	str = NULL;
	if (s)
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(ss) + 1))))
			return (NULL);
		if (ss)
		{
			while (ss[i])
			{
				str[i] = f(ss[i]);
				i++;
			}
		}
		str[i] = '\0';
	}
	return (str);
}
