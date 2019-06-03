/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 11:05:23 by vrabaib           #+#    #+#             */
/*   Updated: 2019/06/03 16:06:46 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*mandelbrot_driver(void *data)
{
	int		tmp;
	t_frac	*frac;

	frac = (t_frac *)data;
	tmp = frac->pfrac.pfrac_y;
	frac->pfrac.pfrac_x = 0;
	while (++frac->pfrac.pfrac_x <= WIDTH)
	{
		frac->pfrac.pfrac_y = tmp;
		while (++frac->pfrac.pfrac_y <= frac->pfrac.pfrac_ymax)
		{
			frac->c.x = 0;
			frac->c.y = 0;
			frac->c.x0 = frac->pfrac.pfrac_x;
			frac->c.y0 = frac->pfrac.pfrac_y;
			frac->c.x_map = mapping(frac->pfrac.pfrac_x, WIDTH, -2.5, 1) \
			/ frac->prop.zoom;
			frac->c.y_map = mapping(frac->pfrac.pfrac_y, HEIGHT, -1, 1) \
			/ frac->prop.zoom;
			mandelbrot_check(frac);
		}
	}
	return (data);
}

void	mandelbrot_check(t_frac *frac)
{
	double xtmp;
	double iteration;

	xtmp = 0;
	iteration = 0;
	while (SQR(frac->c.x) + SQR(frac->c.y) < 4 \
	&& iteration < frac->prop.max_iteration)
	{
		xtmp = SQR(frac->c.x) - SQR(frac->c.y) + frac->c.x_map \
		+ frac->prop.x_shift;
		frac->c.y = 2 * frac->c.x * frac->c.y + frac->c.y_map \
		+ frac->prop.y_shift;
		frac->c.x = xtmp;
		iteration++;
	}
	mandelbrot_plot(iteration, frac);
}

void	mandelbrot_plot(double iteration, t_frac *frac)
{
	unsigned int	color;
	double			log_zn;
	double			nu;

	if (iteration < frac->prop.max_iteration)
	{
		log_zn = log(SQR(frac->c.x) + SQR(frac->c.y)) / 2;
		nu = log(log_zn / log(2)) / log(2);
		iteration = iteration + 1 - nu;
		color = PALETTE[(int)iteration % 16];
	}
	else
		color = 0x00000000;
	mlx_pixel_to_img(frac->pfrac.pfrac_x, frac->pfrac.pfrac_y, color, frac);
}

void	mandelbrot_thread(t_frac *frac)
{
	int			i;
	pthread_t	trds[THREADS];
	t_frac		fracs[THREADS];

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy((void *)&fracs[i], (void *)frac, sizeof(t_frac));
		fracs[i].pfrac.pfrac_y = ((double)WIDTH / THREADS) * i;
		fracs[i].pfrac.pfrac_ymax = ((double)WIDTH / THREADS) * (i + 1);
		pthread_create(&trds[i], NULL, mandelbrot_driver, &fracs[i]);
		i += 1;
	}
	while (i--)
		pthread_join(trds[i], NULL);
	mlx_put_image_to_window(frac->display.init, frac->display.win, \
	frac->image.img, 0, 0);
}
