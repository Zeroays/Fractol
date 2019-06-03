/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:24:52 by vrabaib           #+#    #+#             */
/*   Updated: 2019/06/02 21:01:01 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void fractal_instructions(t_frac *frac)
{
    mlx_string_put(frac->image.img, frac->display.win, WIDTH / 60, HEIGHT / 80, WHITE, "MOVE : ARROW KEYS");
    mlx_string_put(frac->image.img, frac->display.win, WIDTH / 60, HEIGHT / 20, WHITE, "SCROLL +/- : MOUSE WHEEL");
    mlx_string_put(frac->image.img, frac->display.win, WIDTH / 60, HEIGHT / 11, WHITE, "ITERATION + : E");
    mlx_string_put(frac->image.img, frac->display.win, WIDTH / 60, HEIGHT / 7.5, WHITE, "ITERATION - : X");
    mlx_string_put(frac->image.img, frac->display.win, WIDTH / 60, HEIGHT / 5.75, WHITE, "COLOR : C");
    mlx_string_put(frac->image.img, frac->display.win, WIDTH / 60, HEIGHT / 4.65, WHITE, "RESET : R");
    mlx_string_put(frac->image.img, frac->display.win, WIDTH / 60, HEIGHT / 3.95, WHITE, "CLOSE : ESC");
    mlx_string_put(frac->image.img, frac->display.win, WIDTH / 60, HEIGHT / 4.65, WHITE, "RESET : R");
    mlx_string_put(frac->image.img, frac->display.win, WIDTH / 60, HEIGHT / 3.95, WHITE, "CLOSE : ESC");
    mlx_string_put(frac->image.img, frac->display.win, WIDTH / 60, HEIGHT / 1.05, WHITE, ft_strjoin("MAX ITERATIONS : ", ft_itoa(frac->prop.max_iteration)));
}

void mlx_set_prop(t_frac *frac)
{
    frac->prop.max_iteration = 42;
    frac->prop.x_shift = 0;
    frac->prop.y_shift = 0;
    frac->mouse.mouse_x = 0;
    frac->mouse.mouse_y = 0;
    frac->prop.zoom = 1;
    if (ft_strcmp(frac->prop.fractal, "mandelbrot"))
        frac->prop.zoom = 0.5;
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
        ft_memcpy(frac->image.data + 4 * WIDTH * y + x * 4, &color, sizeof(int));
}