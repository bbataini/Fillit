/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:11:27 by kberisha          #+#    #+#             */
/*   Updated: 2017/12/18 12:23:38 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		init_map(t_a *a, int nb)
{
	int		i;
	int		x;
	int		cnt;

	i = 0;
	while (i * i <= nb * 3)
		i++;
	cnt = i * i + i;
	if (!(a->map = ft_strnew(cnt + 1)))
		return (-1);
	x = 0;
	while (x < cnt)
	{
		a->map[x] = '.';
		x++;
	}
	a->map_size = x;
	x = 1;
	while (x <= i)
	{
		a->map[i * x + x - 1] = '\n';
		x++;
	}
	return (0);
}

int		put_tetri_norm(t_a *a, int i, int x, int l)
{
	int		sharp;

	sharp = 0;
	if (a->nb_tetri != 0)
	{
		while (sharp != 4)
		{
			if (a->tmp->pattern[x] == '\n')
				i = i + l - 4;
			if (a->tmp->pattern[x] == '#' && a->map[i + x] == '.')
			{
				sharp++;
				a->map[i + x] = a->tmp->letter;
			}
			else if (a->tmp->pattern[x] == '#' && a->map[i + x] != '.')
			{
				clean_tetri(a, a->tmp->letter);
				return (-1);
			}
			x++;
		}
		return (0);
	}
	return (-1);
}

int		put_tetri(t_a *a, int i)
{
	int		x;
	int		l;

	l = 0;
	x = 0;
	if (a->map[i] != '.')
		return (-1);
	while (a->map[l] != '\n')
		l++;
	if (put_tetri_norm(a, i, x, l) == -1)
		return (-1);
	return (0);
}

void	clean_tetri(t_a *a, char letter)
{
	int		x;
	int		sharp;

	x = 0;
	sharp = 0;
	while (a->map[x] && sharp != 4)
	{
		if (a->map[x] == letter)
		{
			a->map[x] = '.';
			sharp++;
		}
		x++;
	}
}

int		backtracking(t_a *a, t_tetri *tmp)
{
	int		i;

	a->tmp = tmp;
	i = 0;
	while (a->map[i])
	{
		if (put_tetri(a, i) == 0)
		{
			if (!a->tmp->next)
			{
				tmp = a->tmp->previous;
				return (0);
			}
			if (backtracking(a, a->tmp->next) == 0)
				return (0);
			else
			{
				a->tmp = a->tmp->previous;
				clean_tetri(a, a->tmp->letter);
			}
		}
		i++;
	}
	return (-1);
}
