/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:51:28 by kberisha          #+#    #+#             */
/*   Updated: 2017/12/18 12:23:26 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	t_a		a;
	int		fd;
	int		ret;

	ret = 1;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit sample.fillit\n");
		exit(EXIT_FAILURE);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error();
	if (init_struct(&a) == -1)
		return (-1);
	if (ft_parse(&a, fd, ret) == 0)
	{
		if (fillit(&a) == -1)
			return (-1);
	}
	else
		ft_error();
	close(fd);
	return (0);
}
