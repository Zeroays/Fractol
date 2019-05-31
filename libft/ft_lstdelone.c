/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:38:05 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/20 14:21:30 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst_p;

	lst_p = *alst;
	if (alst && del)
	{
		del((lst_p)->content, (lst_p)->content_size);
		free(lst_p);
		*alst = (NULL);
	}
}
