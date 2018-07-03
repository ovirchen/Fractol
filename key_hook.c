/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:47:52 by ovirchen          #+#    #+#             */
/*   Updated: 2018/02/22 15:47:53 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	key_move(int keycode, t_mlx *all)
{
	if (keycode == 0 || keycode == 123)
		move_map_left(all);
	else if (keycode == 2 || keycode == 124)
		move_map_right(all);
	else if (keycode == 13 || keycode == 126)
		move_map_up(all);
	else if (keycode == 1 || keycode == 125)
		move_map_down(all);
}

static void	key_zoom(int keycode, t_mlx *all)
{
	if (keycode == 24 || keycode == 69)
	{
		all->zoom *= 1.1;
		all->f(all);
	}
	else if (keycode == 27 || keycode == 78)
	{
		all->zoom *= 0.9;
		all->f(all);
	}
}

static void	key_color(int keycode, t_mlx *all)
{
	if (keycode == 18)
		all->psycho += 1;
	else if (keycode == 19)
		all->psycho -= 1;
	if (keycode == 18 || keycode == 19)
		all->f(all);
}

static void	enter(int keycode, t_mlx *all)
{
	if (keycode == 36)
	{
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
		all->f(all);
	}
}

int			my_key_funct(int keycode, t_mlx *all)
{
	if (keycode == 53)
	{
		mlx_destroy_window(all->mlx, all->win);
		exit(0);
	}
	else if (keycode == 115)
	{
		all->max_iter += 1;
		all->f(all);
	}
	else if (keycode == 119)
	{
		all->max_iter -= 1;
		if (all->max_iter == 0)
			all->max_iter = 1;
		all->f(all);
	}
	else if (keycode == 49)
		all->lock += 1;
	enter(keycode, all);
	key_move(keycode, all);
	key_zoom(keycode, all);
	key_color(keycode, all);
	return (0);
}
