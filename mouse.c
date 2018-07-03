/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:47:10 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/14 15:47:11 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mouse_zoom(t_mlx *all, int x, int y, int i)
{
	double re;
	double im;
	double zoom;

	zoom = 0.9;
	if (i == 1)
		zoom = 1.1;
	re = 1.0 * x / (WIN_X / (all->re_max - all->re_min)) + all->re_min;
	im = 1.0 * y / (WIN_Y / (all->im_max - all->im_min)) + all->im_min;
	all->re_min = re + (all->re_min - re) / zoom;
	all->re_max = re + (all->re_max - re) / zoom;
	all->im_min = im + (all->im_min - im) / zoom;
	all->im_max = im + (all->im_max - im) / zoom;
	all->center_x = all->re_max + all->re_min;
	all->center_y = all->im_max + all->im_min;
	all->f(all);
}

int			mouse_hook(int x, int y, t_mlx *all)
{
	if (all->f == julia && all->lock % 2 == 0)
	{
		all->mouse_x = 3 * (x - WIN_X / 2) / (all->zoom * WIN_X)
			+ all->center_x;
		all->mouse_y = 2 * (y - WIN_Y / 2) / (all->zoom * WIN_Y)
			+ all->center_y;
		all->f(all);
	}
	return (0);
}

int			mouse_scroll(int button, int x, int y, t_mlx *all)
{
	if (button == 4)
	{
		all->zoom *= 0.9;
		mouse_zoom(all, x, y, 0);
	}
	else if (button == 5)
	{
		all->zoom *= 1.1;
		mouse_zoom(all, x, y, 1);
	}
	return (0);
}
