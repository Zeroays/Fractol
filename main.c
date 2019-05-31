/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:59:24 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/30 19:36:09 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"
#include <stdio.h>

void mlx_set_window(t_frac *frac)
{
    if (!(frac->display.init = mlx_init()))
        fdf_exit(INIT_FAILURE);
    if (!(frac->display.win = mlx_new_window(frac->display.init, \
    WIDTH, HEIGHT, TITLE)))
        fdf_exit(WINDOW_FAILURE);
}

// void *debug(void *sample)
// {
//     t_frac *frac;
//     frac = (t_frac *)sample;

//     printf("%f", frac->pfrac.pfrac_x);
//     //printf("%f %f\n", frac->c.x, frac->c.y);
//     return NULL;
// }

int main(int argc, char *argv[])
{
    pthread_t tab;
    t_frac *frac;

    frac = NULL;
    if (argc == 2)
    {
        if (!(valid_input(argv[1])))
            fdf_exit(USAGE);
        frac = (t_frac *)malloc(sizeof(t_frac));
        mlx_set_window(frac);
        mlx_set_img(frac);
        mlx_set_prop(frac);
        frac->prop.fractal = argv[1];
        dispatch(frac);
        // pthread_create(&tab, NULL, debug, frac);
        // pthread_join(tab, NULL);
        mlx_put_image_to_window(frac->display.init, frac->display.win, frac->image.img, 0, 0);
        mlx_hook(frac->display.win, KEY_PRESS, 3, key_press, frac);
        mlx_hook(frac->display.win, MOUSE_PRESS, 3, mouse_press, frac);
        mlx_hook(frac->display.win, MOUSE_MOVE, 3, mouse_move, frac);
        mlx_hook(frac->display.win, X_BUTTON, 3, terminate, frac);
        mlx_loop(frac->display.init); 
    }
    else
        fdf_exit(USAGE);
}