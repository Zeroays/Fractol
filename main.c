/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:59:24 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/28 15:23:19 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int valid_input(char *argv)
{
    if (!(ft_strcmp(argv, "mandelbrot")))
        return (1);
    else if (!(ft_strcmp(argv, "julia")))
        return (1);
    else if (!(ft_strcmp(argv, "tricorn")))
        return (1);
    return (0);
}

void mlx_set_window(t_frac *frac)
{
    if (!(frac->display.init = mlx_init()))
        fdf_exit(INIT_FAILURE);
    if (!(frac->display.win = mlx_new_window(frac->display.init, \
    WIDTH, HEIGHT, TITLE)))
        fdf_exit(WINDOW_FAILURE);
}

int main(int argc, char *argv[])
{
    t_frac *frac;

    frac = NULL;
    if (argc == 2)
    {
        if (!(valid_input(argv[1])))
            fdf_exit(USAGE);
        frac = (t_frac *)malloc(sizeof(t_frac));
        mlx_set_window(frac);
        mlx_set_img(frac);
        //julia_setup(frac);
        julia_driver(frac);
        // char *data = mlx_get_data_addr(frac->image.img, &frac->image.bpp, &frac->image.sizeline, &frac->image.endian);
	    // for (int i = 0; i < WIDTH; i++)
		//     for (int j = 0; j < HEIGHT; j++)
		// 	    *(int *)&data[(i * frac->image.bpp >> 3) + (j * frac->image.sizeline)] = rand() % 0xFFFFFF;
        mlx_put_image_to_window(frac->display.init, frac->display.win, frac->image.img, 0, 0);
        // mlx_hook(frac->display.win, KEY_PRESS, 3, key_press, frac);
        mlx_hook(frac->display.win, MOUSE_PRESS, 3, mouse_press, frac);
        // mlx_hook(frac->display.win, X_BUTTON, 3, terminate, frac);
        mlx_loop(frac->display.init); 
    }
    else
        fdf_exit(USAGE);
}