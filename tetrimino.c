/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:49:50 by kberisha          #+#    #+#             */
/*   Updated: 2017/12/18 12:23:44 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	size_tetri(t_a *a)
{
	int		i;
	int		sharp;

	sharp = 0;
	i = a->tetri->first_case;
	while (a->tetri->shape[i])
	{
		if (a->tetri->shape[i] == '#')
			sharp++;
		i++;
	}
	a->tetri->len = i - 1;
}

void	tetri_pattern(t_a *a)
{
	a->tetri->pattern = ft_strsub(a->tetri->shape, a->tetri->first_case,
			a->tetri->len);
}
