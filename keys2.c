/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:59:18 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/28 18:15:40 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void fractol_iteration(int iteration, t_frac *frac)
{
    if (iteration == ITERATION_UP)
        frac->prop.max_iteration += 1;
    else if (iteration == ITERATION_DOWN)
        frac->prop.max_iteration -= 1;
    dispatch(frac);
}