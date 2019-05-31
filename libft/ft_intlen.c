/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:28:25 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/21 22:09:43 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	i;
	int	len;

	i = n;
	len = 0;
	if (n == 0)
		return (1);
	if (ft_isnegative(n))
		i *= -1;
	while (i)
	{
		i /= 10;
		len++;
	}
	return (len);
}
