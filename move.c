/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:29:54 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/12 16:29:55 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_map_left(t_mlx *all)
{
	all->re_min -= MV / all->zoom;
	all->re_max -= MV / all->zoom;
	all->center_x = all->re_max + all->re_min;
	all->f(all);
}

void	move_map_right(t_mlx *all)
{
	all->re_min += MV / all->zoom;
	all->re_max += MV / all->zoom;
	all->center_x = all->re_max + all->re_min;
	all->f(all);
}

void	move_map_up(t_mlx *all)
{
	all->im_min -= MV / all->zoom;
	all->im_max -= MV / all->zoom;
	all->center_y = all->im_max + all->im_min;
	all->f(all);
}

void	move_map_down(t_mlx *all)
{
	all->im_min += MV / all->zoom;
	all->im_max += MV / all->zoom;
	all->center_y = all->im_max + all->im_min;
	all->f(all);
}
