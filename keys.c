/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 12:56:47 by vrabaib           #+#    #+#             */
/*   Updated: 2019/06/02 19:35:02 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int key_press(int keycode, t_frac *frac)
{
    if (keycode == ESC)
        terminate(frac);
    else if (keycode == RESET)
        reset(frac);
    else if (keycode == COLOR)
        color(frac);
    else if (keycode == LEFT)
        translate(frac, 'l');
    else if (keycode == RIGHT)
        translate(frac, 'r');
    else if (keycode == UP)
        translate(frac, 'u');
    else if (keycode == DOWN)
        translate(frac, 'd');
    else if (keycode == ITERATION_UP)
        fractol_iteration(ITERATION_UP, frac);
    else if (keycode == ITERATION_DOWN)
        fractol_iteration(ITERATION_DOWN, frac);
    return (0);
}

int terminate(t_frac *frac)
{
    free(frac);
    exit(0);
    return (0);
}

void reset(t_frac *frac)
{
    mlx_set_prop(frac);
    dispatch(frac);
}

void color(t_frac *frac)
{
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
    if (direction == 'l')
        frac->prop.x_shift -= 0.01;
    else if (direction == 'r')
        frac->prop.x_shift += 0.01;
    else if (direction == 'u')
        frac->prop.y_shift -= 0.01;
    else if (direction == 'd')
        frac->prop.y_shift += 0.01;
    dispatch(frac);
}

