/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 11:05:23 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/30 20:28:08 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void mandelbrot_setup(t_frac *frac)
{
    frac->c.zoom = 0;
}

void *mandelbrot_driver(void *data)
{
    int tmp;
    t_frac *frac;
    
    frac = (t_frac *)data;
    tmp = frac->pfrac.pfrac_y;
    frac->pfrac.pfrac_x = 0;
    while (++frac->pfrac.pfrac_x < WIDTH)
    {
        frac->pfrac.pfrac_y = tmp;
        while (++frac->pfrac.pfrac_y <= frac->pfrac.pfrac_ymax)
        {
            frac->c.x = 0;
            frac->c.y = 0;
            frac->c.x0 = frac->pfrac.pfrac_x;
            frac->c.y0 = frac->pfrac.pfrac_y;
            frac->c.x_map = mapping(frac->pfrac.pfrac_x, WIDTH, -2.5, 1);
            frac->c.y_map = mapping(frac->pfrac.pfrac_y, HEIGHT, -1, 1);
            mandelbrot_check(frac);
        }
    }
    return (data);
}

void mandelbrot_check(t_frac *frac)
{
    double xtmp;
    double iteration;

    xtmp = 0;
    iteration = 0;
    while (SQR(frac->c.x) + SQR(frac->c.y) < 4 \
    && iteration < frac->prop.max_iteration)
    {
        xtmp = SQR(frac->c.x) - SQR(frac->c.y) + frac->c.x_map + frac->prop.x_shift;
        frac->c.y = 2 * frac->c.x * frac->c.y + frac->c.y_map + frac->prop.y_shift;
        frac->c.x = xtmp;
        iteration++;
    }
    mandelbrot_plot(iteration, frac);
}

void mandelbrot_plot(double iteration, t_frac *frac)
{
    unsigned int color;
    double log_zn;
    double nu;

    // log_zn = 0;
    // nu = 0;
    if (iteration < frac->prop.max_iteration)
    {
        log_zn = log(SQR(frac->c.x) + SQR(frac->c.y)) / 2.0f;
        nu = log(log_zn / log(2)) / log(2);
        iteration = iteration + 1 - nu;
        color = PALETTE[(int)iteration % 16];
        // int color1 = PALETTE[((int)iteration) % 15];
        // int color2 = PALETTE[((int)iteration + 1) % 15];
        // color = linear_interpolation(color1, color2, (double)(iteration - (long)iteration));
    }
    // if (iteration >= 100)
    //     printf("%f", iteration);
    // unsigned int colors[200];
    // for (int i = 0; i < 200; i++) {
    //     colors[i] = (0x000B0023 + (0x00FEAC07 - 0x000B0023) * ((double)i / 200.0));
        // printf("%x\n", colors[i]);
    //}
    // color = colors[(int)iteration];
    // unsigned int color1 = colors[(int)iteration];
    // unsigned int color2 = colors[((int)iteration + 1)];
    // color = linear_interpolation(color1, color2, (double)(iteration - ((long)iteration)));
    //color = linear_interpolation(0x00000000, 0x000B0023, (double)(iteration - ((long)iteration)));
    //printf("%f", (double)(iteration - ((long)iteration)));
    else
        color = 0x00000000;
    //color = linear_interpolation(color1, color2, (double)(iteration - ((long)iteration)));
    // color = colors[(int)iteration % 5];
    mlx_pixel_to_img(frac->pfrac.pfrac_x, frac->pfrac.pfrac_y, color, frac);
}

void mandelbrot_thread(t_frac *frac)
{
    int i;
    pthread_t t[THREADS];
    t_frac tab[THREADS];

    i = 0;
    while (i < THREADS)
    {
        //((double)(1.00 / THREADS) * WIDTH) * i
        ft_memcpy((void *)&tab[i], (void *)frac, sizeof(t_frac));
        tab[i].pfrac.pfrac_y = ((double)(1.00 / THREADS) * WIDTH) * i;
        tab[i].pfrac.pfrac_ymax = ((double)(1.00 / THREADS) * WIDTH) * (i + 1);
        pthread_create(&t[i], NULL, mandelbrot_driver, &tab[i]);
        i += 1;
    }
    while (i--)
        pthread_join(t[i], NULL);
    mlx_put_image_to_window(frac->display.init, frac->display.win, frac->image.img, 0, 0);
}

