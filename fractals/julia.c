/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 15:39:35 by vrabaib           #+#    #+#             */
/*   Updated: 2019/06/02 19:32:23 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void *julia_driver(void *data)
{   
    int tmp;
    t_frac *frac;

    frac = (t_frac *)data;
    tmp = frac->pfrac.pfrac_y;
    frac->pfrac.pfrac_x = 0;
    while (++frac->pfrac.pfrac_x <= WIDTH)
    {
        frac->pfrac.pfrac_y = tmp;
        while (++frac->pfrac.pfrac_y <= frac->pfrac.pfrac_ymax)
        {
            frac->c.x0 = frac->pfrac.pfrac_x;
            frac->c.y0 = frac->pfrac.pfrac_y;
            frac->c.x_map = mapping(frac->c.x0, WIDTH, -2.5, 1) / frac->prop.zoom;
            frac->c.y_map = mapping(frac->c.y0, HEIGHT, -1, 1) / frac->prop.zoom;
            frac->c.x = 0;
            frac->c.y = 0;
            julia_check(frac);
        }
    }
    return (data);
}

void julia_check(t_frac *frac)
{
    double xtmp;
    double iteration;

    xtmp = 0;
    iteration = 0;
    while (SQR(frac->c.x_map) + SQR(frac->c.y_map) < 4 \
    && iteration < frac->prop.max_iteration)
    {
        xtmp = SQR(frac->c.x_map) - SQR(frac->c.y_map) + mapping(frac->mouse.mouse_x, WIDTH, -1, 1);
        frac->c.y_map = 2 * frac->c.x_map * frac->c.y_map + mapping(frac->mouse.mouse_x, HEIGHT, -1, 1);
        frac->c.x_map = xtmp;
        iteration++;
    }
    julia_plot(iteration, frac);
}

void julia_plot(double iteration, t_frac *frac)
{
    unsigned int color;
    double log_zn;
    double nu;

    log_zn = 0;
    nu = 0;
    if (iteration < frac->prop.max_iteration)
    {
        log_zn = log(frac->c.x_map * frac->c.x_map + frac->c.y_map * frac->c.y_map) / 2;
        nu = log(log_zn / log(2)) / log(2);
        iteration = iteration + 1 - nu;
    }
    if (iteration < frac->prop.max_iteration)
        color = PALETTE[(int)iteration % 16];
    else
        color = 0x00000000;
    mlx_pixel_to_img(frac->c.x0, frac->c.y0, color, frac);
}

void julia_thread(t_frac *frac)
{
    int i;
    pthread_t t[THREADS];
    t_frac tab[THREADS];

    i = 0;
    while (i < THREADS)
    {
        ft_memcpy((void *)&tab[i], (void *)frac, sizeof(t_frac));
        tab[i].pfrac.pfrac_y = ((double)(1.00 / THREADS) * WIDTH) * i;
        tab[i].pfrac.pfrac_ymax = ((double)(1.00 / THREADS) * WIDTH) * (i + 1);
        pthread_create(&t[i], NULL, julia_driver, &tab[i]);
        i += 1;
    }
    while (i--)
        pthread_join(t[i], NULL);
    mlx_put_image_to_window(frac->display.init, frac->display.win, frac->image.img, 0, 0);
}

