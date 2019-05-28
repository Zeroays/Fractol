/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:06:47 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/18 18:33:13 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	p = dst;
	while (*src && i < len)
	{
		*p++ = *src++;
		i++;
	}
	while (i < len)
	{
		*p++ = '\0';
		i++;
	}
	return (dst);
}
