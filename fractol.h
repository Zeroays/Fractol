/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:08:44 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/28 15:26:06 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "keys.h"
# include "display.h"
# include "./minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include <errno.h>

#define MAX_ITERATION 200

# define USAGE 1
# define INIT_FAILURE 2
# define WINDOW_FAILURE 3
# define IMG_FAILURE 5

typedef struct s_mlx
{
    void *init;
    void *win;
}              t_mlx;

typedef struct s_img
{
    void *img;
    int bpp;
    int sizeline;
    int endian;
    char *data;
}              t_img;

typedef struct s_complex
{
    int x0;
    int y0;
    double x_map;
    double y_map;
    double x;
    double y;
    double zoom;
    unsigned int color_m;
}               t_complex;

typedef struct s_frac
{
    t_mlx display;
    t_img image;
    t_complex c;
}              t_frac;

void tricorn_setup(t_frac *frac);
void tricorn_driver(t_frac *frac);
void tricorn_check(t_frac *frac);
void tricorn_plot(double iteration, t_frac *frac);

void julia_setup(int x, int y, t_frac *frac);
void julia_driver(t_frac *frac);
void julia_check(t_frac *frac);
void julia_plot(double iteration, t_frac *frac);

void mandelbrot_setup(t_frac *frac);
void mandelbrot_driver(t_frac *frac);
void mandelbrot_check(t_frac *frac);
void mandelbrot_plot(double iteration, t_frac *frac);

int fdf_exit(int code);
int key_press(int keycode, t_frac *frac);
int mouse_press(int mousecode, t_frac *frac);
int terminate(t_frac *frac);

void reset(t_frac *frac);
void color(t_frac *frac);
void translate(t_frac *frac, int direction);
void zoom_io(t_frac *frac);
void fractol_switch(t_frac *frac);

double mapping(double n, int dimension, double min, double max);
int linear_interpolation(int c1, int c2, double num);
void mlx_set_img(t_frac *frac);
void mlx_clear_img(t_frac *frac);
void mlx_pixel_to_img(int x, int y, int color, t_frac *frac);

#endif 