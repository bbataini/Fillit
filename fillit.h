/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:08:30 by kberisha          #+#    #+#             */
/*   Updated: 2017/12/18 12:22:25 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 21

typedef struct	s_tetri
{
	char					letter;
	int						first_case;
	char					*shape;
	int						len;
	char					*pattern;
	struct s_tetri			*next;
	struct s_tetri			*previous;
}				t_tetri;

typedef struct	s_a
{
	char		*buf;
	char		last;
	t_tetri		*tetri;
	t_tetri		*tmp;
	char		*map;
	int			map_size;
	int			nb_tetri;
}				t_a;

int				fillit(t_a *a);

int				ft_create_tetri(char *buf, t_a *a);

int				ft_parse(t_a *a, int fd, int ret);

int				init_map(t_a *a, int nb);

int				put_tetri(t_a *a, int i);

int				backtracking(t_a *a, t_tetri *tmp);

void			size_tetri(t_a *a);

void			tetri_pattern(t_a *a);

int				init_list(t_tetri **tetri);

int				fill_list(t_tetri **tetri, char *buf, t_a *a);

void			reboot_list(t_a *a);

void			get_tmp(t_a *a);

int				init_struct(t_a *a);

void			clean_tetri(t_a *a, char letter);

#endif
