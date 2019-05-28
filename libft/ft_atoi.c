/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:24:31 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/02 11:04:15 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t			i;
	int				neg;
	unsigned long	num;
	unsigned long	limit;

	i = 0;
	neg = 1;
	num = 0;
	limit = (unsigned long)(FT_LONG_MAX / 10);
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((num > limit || (num == limit && (str[i] - '0') > 7)) && neg == 0)
			return (-1);
		else if ((num > limit || (num == limit && (str[i] - '0') > 8)) \
		&& neg == 1)
			return (0);
		num = num * 10 + (str[i++] - '0');
	}
	return (num * neg);
}
