/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 20:32:52 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/01 21:47:41 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_intnew(size_t row, size_t col)
{
	size_t	i;
	int		**int_arr;

	i = 0;
	if (!(row >= 1 && col >= 1))
		return (NULL);
	if (!(int_arr = (int **)malloc(row * sizeof(int *))))
		return (NULL);
	while (i < row)
	{
		if (!(int_arr[i] = (int *)malloc(col * sizeof(int))))
			return (NULL);
		i++;
	}
	return (int_arr);
}
