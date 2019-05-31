/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:56:16 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/20 23:53:04 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;
	int		n_len;

	h = (char *)haystack;
	n = (char *)needle;
	n_len = ft_strlen(n);
	if (!(n_len))
		return ((char *)h);
	while (*h)
	{
		if (*h == *n && ft_strncmp(h, n, n_len) == 0)
			return ((char *)h);
		h++;
	}
	return (NULL);
}
