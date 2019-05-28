/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:39:35 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/28 15:29:52 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia_setup(int x0, int y0, t_frac *frac)
{
    frac->c.x0 = x0;
    frac->c.y0 = y0;
    frac->c.x_map = mapping(x0, WIDTH, -3, 3);
    frac->c.y_map = mapping(y0, HEIGHT, -2, 2);
    frac->c.x = 0;
    frac->c.y = 0;
}

void julia_driver(t_frac *frac)
{
    int x0;
    int y0;
    
    x0 = -1;
    while (++x0 < WIDTH)
    {
        y0 = -1;
        while (++y0 < HEIGHT)
        {
            julia_setup(x0, y0, frac);
            julia_check(frac);
        }
    }
}

void julia_check(t_frac *frac)
{
    double xtmp;
    double iteration;

    xtmp = 0;
    iteration = 0;
    while (frac->c.x_map * frac->c.x_map + frac->c.y_map * frac->c.y_map < 4 \
    && iteration < MAX_ITERATION)
    {
        xtmp = frac->c.x_map * frac->c.x_map - frac->c.y_map * frac->c.y_map;
        frac->c.y_map = 2 * frac->c.x_map * frac->c.y_map + 0.5;
        frac->c.x_map = xtmp + 0.8;
        iteration++;
    }
    julia_plot(iteration, frac);
}

void julia_plot(double iteration, t_frac *frac)
{
    unsigned int color;
    double log_zn;
    double nu;

    log_zn = 0;
    nu = 0;
    if (iteration < MAX_ITERATION)
    {
        log_zn = log(frac->c.x_map * frac->c.x_map + frac->c.y_map * frac->c.y_map) / 2.0f;
        nu = log(log_zn / log(2)) / log(2);
        iteration = iteration + 1 - nu;
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
    unsigned int colors[16] = {0x00431E0F, 0x0019071A, 0x0009012F, 0x0009012F, 0x00000764, 0x000C2C8A, 0x001852B1, 0x00397DD1, 0x0086B5E5, 0x00D3ECF8, 0x00F1E9BF, 0x00F8C95F, 0x00FFAA00, 0x00CC8000, 0x00995700, 0x006A3403};
    if (iteration < MAX_ITERATION)
        color = colors[(int)iteration % 16];
    else
        color = 0x00000000;
    //color = linear_interpolation(color1, color2, (double)(iteration - ((long)iteration)));
    // color = colors[(int)iteration % 5];
    mlx_pixel_to_img(frac->c.x0, frac->c.y0, color, frac);
}

