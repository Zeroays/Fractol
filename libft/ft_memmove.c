/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:52:22 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/18 18:07:06 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*cdst;
	char	*csrc;

	i = -1;
	cdst = (char *)dst;
	csrc = (char *)src;
	if (csrc < cdst)
		while (len--)
			cdst[len] = csrc[len];
	else
		while (++i < len)
			cdst[i] = csrc[i];
	return (dst);
}
