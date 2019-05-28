/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:03:30 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/20 14:29:08 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char const	*p;
	char		*str;

	p = s;
	if (s)
	{
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (*p && start)
		{
			p++;
			start--;
		}
		while (*p && start < len)
			str[start++] = *p++;
		str[start] = '\0';
		return (str);
	}
	return (NULL);
}
