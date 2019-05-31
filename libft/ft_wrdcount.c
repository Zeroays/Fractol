/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:21:01 by vrabaib           #+#    #+#             */
/*   Updated: 2019/02/21 22:10:11 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_wrdcount(char const *str, char c)
{
	int i;
	int wrd_count;

	i = 0;
	wrd_count = 0;
	while (str[i])
	{
		if (str[i] != c)
			wrd_count++;
		while (str[i] != c && str[i + 1])
			i++;
		i++;
	}
	return (wrd_count);
}
