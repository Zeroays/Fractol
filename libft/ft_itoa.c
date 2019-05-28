/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:03:59 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/21 22:23:33 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*p;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	if (ft_isnegative(n))
	{
		len++;
		n *= -1;
		neg = 1;
	}
	if (!(p = malloc(sizeof(char) * len + 1)))
		return (NULL);
	p[len] = '\0';
	while (len)
	{
		p[--len] = n % 10 + '0';
		n /= 10;
	}
	if ((*p) == '0' && neg == 1)
		*p = '-';
	return (p);
}
