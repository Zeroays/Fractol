/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:56:47 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/28 10:14:35 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void reset(t_frac *frac)
{
    mandelbrot_setup(frac);
    mandelbrot_driver(frac);
    mlx_put_image_to_window(frac->display.init, frac->display.win, frac->image.img, 0, 0);
}

void color(t_frac *frac)
{
    // if (frac)
    //     ;
    // mlx_destroy_image((void *)frac->display.init, (void *)frac->image.img);
    // frac->c.color_m = 0x00AAAAAA;
    // mandelbrot_setup(frac);
    // mandelbrot_driver(frac);
    int x0;
    int y0;

    x0 = -1;
    while (++x0 < WIDTH)
    {
        y0 = -1;
        while (++y0 < HEIGHT)
            *(int *)&(frac->image.data)[(x0 * frac->image.bpp >> 3) + \
            (y0 * frac->image.sizeline)] += 0x000000AA;
    }
    mlx_put_image_to_window(frac->display.init, frac->display.win, frac->image.img, 0, 0);
    
}

void translate(t_frac *frac, int direction)
{
    if (frac && direction)
        ;
}

void zoom_io(t_frac *frac)
{
    frac->c.zoom = 0.1;
    if (frac)
        exit(0);
    // mandelbrot_setup(frac);
    // mandelbrot_driver(frac);
    // mlx_put_image_to_window(frac->display.init, frac->display.win, frac->image.img, 0, 0);
    // if (direction && frac)
    //     ;
}

void fractol_switch(t_frac *frac)
{
    if (frac)
        ;
}