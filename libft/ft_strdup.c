/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:34:02 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/27 22:17:06 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1)))
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	str[i] = '\0';
	return (str);
}
