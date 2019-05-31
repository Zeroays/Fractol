/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:10:03 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/28 18:30:06 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void tricorn_setup(int x0, int y0, t_frac *frac)
{
    frac->prop.fractal = "tricorn";
    frac->c.x0 = x0;
    frac->c.y0 = y0;
    frac->c.x_map = mapping(x0, WIDTH, -2.5, 1);
    frac->c.y_map = mapping(y0, HEIGHT, -1, 1);
    frac->c.x = frac->c.x_map;
    frac->c.y = frac->c.y_map;
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
            tricorn_setup(x0, y0, frac);
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
    && iteration < frac->prop.max_iteration)
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

    if (iteration == frac->prop.max_iteration)
        color = 0x00000000;
    else
        color = iteration * NUTMEG_WOOD_FINISH;
    mlx_pixel_to_img(frac->c.x0, frac->c.y0, color, frac);
}