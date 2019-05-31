/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:20:37 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/21 21:22:30 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ltrcount(char const *str, char c)
{
	int i;
	int ltr_count;

	i = 0;
	ltr_count = 0;
	while (str[i])
	{
		if (str[i] != c)
			ltr_count++;
		i++;
	}
	return (ltr_count);
}
