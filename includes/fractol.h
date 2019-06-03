/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:08:44 by vrabaib           #+#    #+#             */
/*   Updated: 2019/06/02 19:37:49 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "keys.h"
# include "mouse.h"
# include "display.h"
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include <errno.h>
# include <pthread.h>

# define USAGE 1
# define INIT_FAILURE 2
# define WINDOW_FAILURE 3
# define IMG_FAILURE 5

# define THREADS 16

# define SQR(X0) (X0 * X0)

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
}               t_complex;

typedef struct s_prop
{
    char *fractal;
    int max_iteration;
    double zoom;
    double x_shift;
    double y_shift;
}              t_prop;

typedef struct s_mouse 
{
    int mouse_x;
    int mouse_y;
}              t_mouse;

typedef struct s_pfrac
{
    double pfrac_x;
    double pfrac_y;
    double pfrac_ymax;
}               t_pfrac;

typedef struct s_frac
{
    t_prop prop;
    t_mouse mouse;
    t_mlx display;
    t_img image;
    t_complex c;
    t_pfrac pfrac;
}              t_frac;

void *mandelbrot_driver(void *data);
void mandelbrot_check(t_frac *frac);
void mandelbrot_plot(double iteration, t_frac *frac);
void mandelbrot_thread(t_frac *frac);

void *julia_driver(void *data);
void julia_check(t_frac *frac);
void julia_plot(double iteration, t_frac *frac);
void julia_thread(t_frac *frac);

void *tricorn_driver(void *data);
void tricorn_check(t_frac *frac);
void tricorn_plot(double iteration, t_frac *frac);
void tricorn_thread(t_frac *frac);

void mlx_set_img(t_frac *frac);
void mlx_clear_img(t_frac *frac);
void mlx_pixel_to_img(int x, int y, int color, t_frac *frac);

int key_press(int keycode, t_frac *frac);
int terminate(t_frac *frac);
void reset(t_frac *frac);
void color(t_frac *frac);
void translate(t_frac *frac, int direction);

void fractol_iteration(int iteration, t_frac *frac);

void mlx_set_window(t_frac *frac);
void mlx_set_prop(t_frac *frac);

int mouse_press(int mousecode, int x, int y, t_frac *frac);
int mouse_move(int x, int y, t_frac *frac);
void fractol_twirl(int x, int y, t_frac *frac);
void zoom_io(int x, int y, int direction, t_frac *frac);

double mapping(double n, int dimension, double min, double max);
int linear_interpolation(int c1, int c2, double num);
int valid_input(char *argv);
int fdf_exit(int code);
void dispatch(t_frac *frac);

#endif 