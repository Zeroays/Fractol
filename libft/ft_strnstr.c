/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:34:05 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/20 23:52:49 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstk, const char *ndle, size_t len)
{
	size_t n;

	n = ft_strlen(ndle);
	if (!(n))
		return ((char *)hstk);
	while (*hstk && n <= len)
	{
		if (*hstk == *ndle && ft_strncmp(hstk, ndle, n) == 0)
			return ((char *)hstk);
		hstk++;
		len--;
	}
	return (NULL);
}
