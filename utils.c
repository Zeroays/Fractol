/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:59:13 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/27 12:22:29 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fdf_exit(int code)
{
	if (code == USAGE)
		ft_putstr_fd("usage ...\n", 0);
	else if (code == INIT_FAILURE)
		ft_putstr_fd("Mlx failed to initialize", 0);
	else if (code == WINDOW_FAILURE)
		ft_putstr_fd("Window failed to initialize", 0);
	else if (code == IMG_FAILURE)
		ft_putstr_fd("Image failed to initialize", 0);
	exit(code);
}

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
        translate(frac, 'l');
    else if (keycode == DOWN)
        translate(frac, 'd');
    else if (keycode == FRACTOL)
        fractol_switch(frac);
    return (0);
}

int mouse_press(int mousecode, t_frac *frac)
{
    if (mousecode == ZOOM_IN)
        zoom_io(frac);
    // else if (mousecode == ZOOM_OUT)
    //     zoom_io(frac);
    return (0);
}

int terminate(t_frac *frac)
{
    //mlx_clear_img(frac);
    //mlx_destroy_image((void *)frac->display.init, (void *)frac->image.img);
    free(frac);
    exit(0);
    return (0);
}