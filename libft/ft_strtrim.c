/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:55:22 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/21 22:22:24 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int	i;
	int	len;

	i = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (ft_iswhitespace(s[i]))
			i++;
		while (ft_iswhitespace(s[len - 1]))
			len--;
		if (len == 0)
			return (ft_strnew(1));
		else
			return (ft_strsub(s, i, len - i));
	}
	else
		return (NULL);
}
