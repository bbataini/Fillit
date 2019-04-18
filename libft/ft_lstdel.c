/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kberisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:46:46 by kberisha          #+#    #+#             */
/*   Updated: 2017/11/26 16:12:39 by kberisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*tmp;

	if (*alst && alst && del)
	{
		current = *alst;
		while (current)
		{
			del(current->content, current->content_size);
			tmp = current->next;
			free(current);
			current = NULL;
			current = tmp;
		}
		*alst = NULL;
		alst = NULL;
	}
}
