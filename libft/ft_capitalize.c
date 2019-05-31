/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:26:07 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/21 22:12:34 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_capitalize(char *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			while (ft_iswhitespace(str[i]))
				i++;
			if (str[i + 1] || str[i + 1] == '\0')
			{
				str[i] = ft_toupper(str[i]);
				i++;
			}
			while (ft_isalnum(str[i]))
			{
				str[i] = ft_tolower(str[i]);
				i++;
			}
		}
		return (str);
	}
	return (NULL);
}
