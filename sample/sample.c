/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:47:19 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/28 15:00:35 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"

#define WIDTH 2000
#define HEIGHT 1200

typedef struct	s_mlx
{
	int	content;
	void *mlx;
	int bpp;
	int size_line;
	int endian;
}				t_mlx;

typedef struct	s_win
{
	void *init;
	void *window;
	t_mlx *img;
}				t_win;

void zoom_in(t_win *program)
{
	char *data = mlx_get_data_addr(program->img->mlx, &program->img->bpp, &program->img->size_line, &program->img->endian);
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < HEIGHT; j++)
			*(int *)&data[(i * program->img->bpp >> 3) + (j * program->img->size_line)] = rand() % 0xFFFFFF;
	mlx_put_image_to_window(program->init, program->window,program->img->mlx,0,0);
}

int key_press(int keycode, t_win *program)
{
	if (keycode == 8 && program)
		zoom_in(program);
	return (0);
}

int mouse_press(int mousecode, int x, int y, t_win *program)
{
	if (x || y)
		;
	if (mousecode == 4 && program && (x >= 0 && x <= 400) && (y >= 0 && y <= 400)) {
		zoom_in(program);
	}
	return (0);
}


int main(void)
{
	t_win *program;

	program = (t_win *)malloc(sizeof(t_win));
	program->init = mlx_init();
	program->window = mlx_new_window(program->init, WIDTH, HEIGHT, "Hello World");
	program->img->mlx = mlx_new_image(program->init, WIDTH, HEIGHT);
	program->img->bpp = 32;
	program->img->size_line = 32 * WIDTH;
	program->img->endian = 0;
	char *data = mlx_get_data_addr(program->img->mlx, &program->img->bpp, &program->img->size_line, &program->img->endian);
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < HEIGHT; j++)
			*(int *)&data[(i * program->img->bpp >> 3) + (j * program->img->size_line)] = rand() % 0xFFFFFF;	
	mlx_put_image_to_window(program->init, program->window,program->img->mlx,0,0);
	//mlx_destroy_image(program->init,program->img->mlx);
	mlx_hook(program->window, 4, 4, mouse_press, program);
	mlx_hook(program->window, 2, 3, key_press, program);
	mlx_loop(program->init);
}
