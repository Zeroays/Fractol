/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 11:05:23 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/28 15:16:26 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

//-2.5, 1
//-1, 1

void mandelbrot_setup(t_frac *frac)
{
    frac->c.zoom = 0;
}

void mandelbrot_driver(t_frac *frac)
{
    int x0;
    int y0;
    
    x0 = -1;
    
    while (++x0 < WIDTH)
    {
        y0 = -1;
        while (++y0 < HEIGHT)
        {
            frac->c.x = 0;
            frac->c.y = 0;
            frac->c.x0 = x0;
            frac->c.y0 = y0;
            frac->c.x_map = mapping(x0, WIDTH, -2.5, 1);
            frac->c.y_map = mapping(y0, HEIGHT, -1, 1);
            mandelbrot_check(frac);
        }
    }
}

void mandelbrot_check(t_frac *frac)
{
    double xtmp;
    double iteration;

    xtmp = 0;
    iteration = 0;
    while (frac->c.x * frac->c.x + frac->c.y * frac->c.y < 4 \
    && iteration < MAX_ITERATION)
    {
        xtmp = frac->c.x * frac->c.x - frac->c.y * frac->c.y + frac->c.x_map + 1;
        frac->c.y = 2 * frac->c.x * frac->c.y + frac->c.y_map + 0.4;
        frac->c.x = xtmp;
        iteration++;
    }
    mandelbrot_plot(iteration, frac);
}

void mandelbrot_plot(double iteration, t_frac *frac)
{
    unsigned int color;
    double log_zn;
    double nu;

    // log_zn = 0;
    // nu = 0;
    if (iteration < MAX_ITERATION)
    {
        log_zn = log(frac->c.x * frac->c.x + frac->c.y * frac->c.y) / 2.0f;
        nu = log(log_zn / log(2)) / log(2);
        iteration = iteration + 1 - nu;
        int color1 = PALETTE[((int)iteration) % 15];
        int color2 = PALETTE[((int)iteration + 1) % 15];
        color = linear_interpolation(color1, color2, (double)(iteration - (long)iteration));
    }
    // if (iteration >= 100)
    //     printf("%f", iteration);
    // unsigned int colors[200];
    // for (int i = 0; i < 200; i++) {
    //     colors[i] = (0x000B0023 + (0x00FEAC07 - 0x000B0023) * ((double)i / 200.0));
        // printf("%x\n", colors[i]);
    //}
    // color = colors[(int)iteration];
    // unsigned int color1 = colors[(int)iteration];
    // unsigned int color2 = colors[((int)iteration + 1)];
    // color = linear_interpolation(color1, color2, (double)(iteration - ((long)iteration)));
    //color = linear_interpolation(0x00000000, 0x000B0023, (double)(iteration - ((long)iteration)));
    //printf("%f", (double)(iteration - ((long)iteration)));
    else
        color = 0x00000000;
    //color = linear_interpolation(color1, color2, (double)(iteration - ((long)iteration)));
    // color = colors[(int)iteration % 5];
    mlx_pixel_to_img(frac->c.x0, frac->c.y0, color, frac);
}



