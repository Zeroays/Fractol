/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:10:03 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/27 11:24:38 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void tricorn_setup(t_frac *frac)
{
    frac->c.zoom = 0;
}

void tricorn_driver(t_frac *frac)
{
    int x0;
    int y0;
    
    x0 = -1;
    
    while (++x0 < WIDTH)
    {
        y0 = -1;
        while (++y0 < HEIGHT)
        {
            frac->c.x0 = x0;
            frac->c.y0 = y0;
            frac->c.x_map = mapping(x0, WIDTH, -2.5, 1);
            frac->c.y_map = mapping(y0, HEIGHT, -1, 1);
            frac->c.x = frac->c.x_map;
            frac->c.y = frac->c.y_map;
            tricorn_check(frac);
        }
    }
}

void tricorn_check(t_frac *frac)
{
    double xtmp;
    double iteration;

    xtmp = 0;
    iteration = 0;
    while (frac->c.x * frac->c.x+ frac->c.y * frac->c.y < 4 \
    && iteration < MAX_ITERATION)
    {
        xtmp = frac->c.x * frac->c.x - frac->c.y * frac->c.y + frac->c.x_map;
        frac->c.y = -2 * frac->c.x * frac->c.y + frac->c.y_map;
        frac->c.x = xtmp;
        iteration++;
    }
    tricorn_plot(iteration, frac);
}

void tricorn_plot(double iteration, t_frac *frac)
{
    unsigned int color;

    if (iteration == MAX_ITERATION)
        color = 0x00000000;
    else
        color = iteration * NUTMEG_WOOD_FINISH;
    mlx_pixel_to_img(frac->c.x0, frac->c.y0, color, frac);
}