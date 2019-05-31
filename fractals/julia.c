/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:39:35 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/28 19:22:25 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void julia_setup(int x0, int y0, t_frac *frac)
{
    frac->prop.fractal = "julia";
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
    && iteration < frac->prop.max_iteration)
    {
        xtmp = frac->c.x_map * frac->c.x_map - frac->c.y_map * frac->c.y_map;
        frac->c.y_map = 2 * frac->c.x_map * frac->c.y_map + frac->mouse.mouse_y / (HEIGHT / 2);
        frac->c.x_map = xtmp + frac->mouse.mouse_x / (WIDTH / 2);
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
    if (iteration < frac->prop.max_iteration)
    {
        log_zn = log(frac->c.x_map * frac->c.x_map + frac->c.y_map * frac->c.y_map) / 2.0f;
        nu = log(log_zn / log(2)) / log(2);
        iteration = iteration + 1 - nu;
    }
    //unsigned int colors[16] = {0x00431E0F, 0x0019071A, 0x0009012F, 0x0009012F, 0x00000764, 0x000C2C8A, 0x001852B1, 0x00397DD1, 0x0086B5E5, 0x00D3ECF8, 0x00F1E9BF, 0x00F8C95F, 0x00FFAA00, 0x00CC8000, 0x00995700, 0x006A3403};
    if (iteration < frac->prop.max_iteration)
        color = PALETTE[(int)iteration % 16];
    else
        color = 0x00000000;
    mlx_pixel_to_img(frac->c.x0, frac->c.y0, color, frac);
}

