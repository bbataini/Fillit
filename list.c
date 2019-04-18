/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:59:45 by kberisha          #+#    #+#             */
/*   Updated: 2017/12/18 12:23:20 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		init_list(t_tetri **tetri)
{
	if (!(*tetri = (t_tetri *)malloc(sizeof(t_tetri))))
		return (-1);
	(*tetri)->previous = NULL;
	(*tetri)->first_case = 0;
	(*tetri)->shape = NULL;
	(*tetri)->len = 0;
	(*tetri)->letter = '?';
	(*tetri)->next = NULL;
	(*tetri)->pattern = NULL;
	return (0);
}

int		fill_list(t_tetri **tetri, char *buf, t_a *a)
{
	int			i;

	i = 0;
	while (buf[i] && buf[i] != '#')
		i++;
	(*tetri)->letter = a->last;
	(*tetri)->shape = (char *)malloc(sizeof(char) * ft_strlen(buf) + 1);
	(*tetri)->shape = buf;
	(*tetri)->first_case = i;
	size_tetri(a);
	tetri_pattern(a);
	return (0);
}

void	reboot_list(t_a *a)
{
	while (a->tetri->previous)
		a->tetri = a->tetri->previous;
}

void	get_tmp(t_a *a)
{
	a->tmp = a->tetri;
}
