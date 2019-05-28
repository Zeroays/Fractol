/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:24:52 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/27 12:21:05 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double mapping(double n, int dimension, double min, double max)
{
    return ((n / dimension) * (max - min) + min);
}

int linear_interpolation(int c1, int c2, double num)
{
    return ((c2 - c1) * num + c1);
}

void mlx_set_img(t_frac *frac)
{
    if (!(frac->image.img = mlx_new_image(frac->display.init, WIDTH, HEIGHT)))
        fdf_exit(IMG_FAILURE);
	frac->image.bpp = 32;
	frac->image.sizeline = frac->image.bpp * WIDTH;
	frac->image.endian = 0;
    frac->image.data = mlx_get_data_addr(frac->image.img, &frac->image.bpp, \
    &frac->image.sizeline, &frac->image.endian);
}

void mlx_clear_img(t_frac *frac)
{
    char *data;
    
    data = frac->image.data;
    ft_bzero((void *)data, HEIGHT * WIDTH * frac->image.bpp);
}

void mlx_pixel_to_img(int x, int y, int color, t_frac *frac)
{
    *(int *)&(frac->image.data)[(x * frac->image.bpp >> 3) + \
    (y * frac->image.sizeline)] = color;
}