/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:22:16 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/20 14:20:46 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *n_lst;

	lst = *alst;
	if (alst && del)
	{
		while (lst)
		{
			n_lst = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = n_lst;
		}
		*alst = (NULL);
	}
}
