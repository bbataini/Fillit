/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:41:04 by kberisha          #+#    #+#             */
/*   Updated: 2017/12/18 12:23:04 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(t_a *a)
{
	if (init_map(a, a->nb_tetri) == -1)
		return (-1);
	reboot_list(a);
	get_tmp(a);
	while (backtracking(a, a->tmp) != 0)
	{
		if (a->nb_tetri == 0)
		{
			ft_putstr("error\n");
			exit(EXIT_FAILURE);
		}
		a->nb_tetri++;
		get_tmp(a);
		if (init_map(a, a->nb_tetri) == -1)
			return (-1);
	}
	ft_putstr(a->map);
	return (0);
}
