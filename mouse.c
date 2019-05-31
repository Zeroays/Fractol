/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:59:13 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/28 19:12:01 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int mouse_press(int mousecode, int x, int y, t_frac *frac)
{
    (void)x;
    (void)y;
    if (mousecode == MOUSE_LEFT)
        fractol_switch(frac);
    else if (mousecode == MOUSE_RIGHT)
        fractol_switch(frac);
    else if (mousecode == SCROLL_UP)
        zoom_io(SCROLL_UP, frac);
    else if (mousecode == SCROLL_DOWN)
        zoom_io(SCROLL_DOWN, frac);
    return (0);
}

int mouse_move(int x, int y, t_frac *frac)
{
    if (!(ft_strcmp(frac->prop.fractal, "julia"))) 
    {
        //mlx_clear_img(frac);
        //mlx_clear_window(frac->display.init, frac->display.win);
        fractol_twirl(x, y, frac);
    } 
    return (0);
}

void fractol_twirl(int x, int y, t_frac *frac)
{
    frac->mouse.mouse_x = x;
    frac->mouse.mouse_y = y;
    dispatch(frac);
}

void fractol_switch(t_frac *frac)
{
    if (frac)
        ;
}

void zoom_io(int direction, t_frac *frac)
{
    if (direction == SCROLL_UP)
        frac->prop.zoom += 0.1;
    else if (direction == SCROLL_DOWN)
        frac->prop.zoom -= 0.1;
    dispatch(frac);
}