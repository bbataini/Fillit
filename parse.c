/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:34:00 by kberisha          #+#    #+#             */
/*   Updated: 2017/12/18 12:23:33 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_links(char *buf)
{
	int		i;
	int		links;

	i = 0;
	links = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if ((i + 1) < 20 && buf[i + 1] == '#')
				links++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				links++;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				links++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				links++;
		}
		i++;
	}
	if (links == 6 || links == 8)
		return (0);
	return (-1);
}

static int	ft_is_valid(char *buf, int ret)
{
	int		i;
	int		sharp;

	sharp = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (buf[i] != '.' && buf[i] != '#')
				return (-1);
			if (buf[i] == '#')
				sharp++;
		}
		else if (buf[i] != '\n')
			return (-1);
		i++;
	}
	if (sharp != 4)
		return (-1);
	if (ret == 21 && buf[i] != '\n')
		return (-1);
	if (ft_links(buf) == -1)
		return (-1);
	return (0);
}

int			ft_create_tetri(char *buf, t_a *a)
{
	if (a->nb_tetri != 0)
	{
		a->tmp = a->tetri;
		if (init_list(&a->tetri->next) == -1)
			return (-1);
		a->tetri = a->tetri->next;
		a->tetri->previous = a->tmp;
	}
	fill_list(&a->tetri, buf, a);
	a->nb_tetri++;
	return (0);
}

int			ft_parse(t_a *a, int fd, int ret)
{
	char			tmp[BUF_SIZE + 1];
	char			buf[BUF_SIZE + 1];

	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (ft_strlen(buf) < 20)
			return (-1);
		buf[ret] = '\0';
		if ((ft_is_valid(buf, ret) == -1) || ((a->nb_tetri) == 26))
			return (-1);
		if (ft_create_tetri(buf, a) == -1)
			return (-1);
		a->last++;
		ft_memcpy(tmp, buf, BUF_SIZE + 1);
		ft_strclr(buf);
	}
	if (tmp[20] == '\n' || tmp[0] == '\0')
		return (-1);
	return (0);
}
