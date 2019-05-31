/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 19:18:15 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/21 22:14:16 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lst_p;

	if (lst && f)
	{
		lst_p = f(lst);
		lst_p->next = ft_lstmap(lst->next, f);
		return (lst_p);
	}
	return (NULL);
}
