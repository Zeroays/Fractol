/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:10:03 by vrabaib           #+#    #+#             */
/*   Updated: 2019/06/03 13:07:56 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*tricorn_driver(void *data)
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
			frac->c.x0 = frac->pfrac.pfrac_x;
			frac->c.y0 = frac->pfrac.pfrac_y;
			frac->c.x_map = mapping(frac->c.x0, WIDTH + WIDTH \
			* frac->prop.x_shift, -2.5, 1) / frac->prop.zoom;
			frac->c.y_map = mapping(frac->c.y0, HEIGHT + HEIGHT \
			* frac->prop.y_shift, -1, 1) / frac->prop.zoom;
			frac->c.x = frac->c.x_map;
			frac->c.y = frac->c.y_map;
			tricorn_check(frac);
		}
	}
	return (data);
}

void	tricorn_check(t_frac *frac)
{
	double	xtmp;
	double	iteration;

	xtmp = 0;
	iteration = 0;
	while (SQR(frac->c.x) + SQR(frac->c.y) < 4 \
	&& iteration < frac->prop.max_iteration)
	{
		xtmp = SQR(frac->c.x) - SQR(frac->c.y) + frac->c.x_map;
		frac->c.y = -2 * frac->c.x * frac->c.y + frac->c.y_map;
		frac->c.x = xtmp;
		iteration++;
	}
	tricorn_plot(iteration, frac);
}

void	tricorn_plot(double iteration, t_frac *frac)
{
	unsigned int color;

	if (iteration == frac->prop.max_iteration)
		color = 0x00000000;
	else
		color = iteration * NUTMEG_WOOD_FINISH;
	mlx_pixel_to_img(frac->c.x0, frac->c.y0, color, frac);
}

void	tricorn_thread(t_frac *frac)
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
		pthread_create(&trds[i], NULL, tricorn_driver, &fracs[i]);
		i += 1;
	}
	while (i--)
		pthread_join(trds[i], NULL);
	mlx_put_image_to_window(frac->display.init, frac->display.win, \
	frac->image.img, 0, 0);
}
