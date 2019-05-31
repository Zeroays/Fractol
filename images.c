/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:24:52 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/30 20:32:54 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void mlx_set_prop(t_frac *frac)
{
    frac->prop.max_iteration = 200;
    frac->prop.x_shift = 0;
    frac->prop.y_shift = 0;
    frac->prop.zoom = 0;
    frac->mouse.mouse_x = 0;
    frac->mouse.mouse_y = 0;
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
    ft_bzero(frac->image.data, HEIGHT * WIDTH * frac->image.bpp);
}

void mlx_pixel_to_img(int x, int y, int color, t_frac *frac)
{
    if (x < WIDTH && y < HEIGHT)
    // color = mlx_get_color_value(frac->mlx, color);
    // ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4, &color, sizeof(int));
        *(int *)&(frac->image.data)[(x * frac->image.bpp >> 3) + \
        (y * frac->image.sizeline)] = color;
    // if (x < WIDTH && y < HEIGHT)
    //     ft_memcpy(frac->image.data + 4 * WIDTH * y + x * 4, &color, sizeof(int));
}