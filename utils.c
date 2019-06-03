/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:41:48 by vrabaib           #+#    #+#             */
/*   Updated: 2019/06/01 18:21:15 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

double mapping(double n, int dimension, double min, double max)
{
    return ((n / dimension) * (max - min) + min);
}

int linear_interpolation(int c1, int c2, double num)
{
    return ((c2 - c1) * num + c1);
}

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

void dispatch(t_frac *frac)
{
    if (!(ft_strcmp(frac->prop.fractal, "mandelbrot")))
        mandelbrot_thread(frac);
    else if (!(ft_strcmp(frac->prop.fractal, "julia")))
        julia_thread(frac);
    else if (!(ft_strcmp(frac->prop.fractal, "tricorn")))
        tricorn_thread(frac);
}