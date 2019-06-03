/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:59:13 by vrabaib           #+#    #+#             */
/*   Updated: 2019/06/02 19:45:39 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int mouse_press(int mousecode, int x, int y, t_frac *frac)
{
    if (ft_strcmp(frac->prop.fractal, "julia"))
    {
        if (mousecode == SCROLL_UP)
            zoom_io(x, y, SCROLL_UP, frac);
        else if (mousecode == SCROLL_DOWN)
            zoom_io(x, y, SCROLL_DOWN, frac);
    }
    return (0);
}

int mouse_move(int x, int y, t_frac *frac)
{
    if (!(ft_strcmp(frac->prop.fractal, "julia")))
        fractol_twirl(x, y, frac);
    return (0);
}

void fractol_twirl(int x, int y, t_frac *frac)
{
    frac->mouse.mouse_x = x;
    frac->mouse.mouse_y = y;
    dispatch(frac);
}

void zoom_io(int x, int y, int direction, t_frac *frac)
{
    if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
    {
        if (direction == SCROLL_UP) 
        {
            frac->prop.zoom += 0.5;
            frac->prop.max_iteration += 2;
        }
        else if (direction == SCROLL_DOWN) 
        {
            frac->prop.zoom -= 0.5;
            frac->prop.max_iteration -= 2;
        }
        frac->mouse.mouse_x = x;
        frac->mouse.mouse_y = y;
    }
    dispatch(frac);
}