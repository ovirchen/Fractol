/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:39:57 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/11 16:39:58 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_mlx *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WIN_X, WIN_Y, all->name);
	all->img = mlx_new_image(all->mlx, WIN_X, WIN_Y);
	all->map = mlx_get_data_addr(all->img, &(all->bit_per_pxl),
		&(all->size_line), &(all->endian));
	all->zoom = 1;
	all->psycho = 0;
	all->max_iter = 80;
	all->re_min = -1.5;
	all->re_max = 1.5;
	all->im_min = -1;
	all->im_max = 1;
	all->center_x = 0;
	all->center_y = 0;
	all->lock = 0;
}

int		init_function(char *filename, t_mlx *all)
{
	if (ft_strcmp(filename, "Mandelbrot") == 0)
	{
		all->name = "Mandelbrot Set";
		all->f = mandelbrot;
	}
	else if (ft_strcmp(filename, "Julia") == 0)
	{
		all->name = "Julia Set";
		all->f = julia;
	}
	else if (ft_strcmp(filename, "BurningShip") == 0)
	{
		all->name = "Burning Ship Set";
		all->f = burningship;
	}
	else if (ft_strcmp(filename, "Heart") == 0)
	{
		all->name = "Heart Set";
		all->f = heart;
	}
	else
		return (ft_usage());
	return (0);
}
