/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:38:11 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/15 15:46:25 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		rectangle(t_mlx *all, int x_1, int y_1, int x_2, int y_2)
{
	int x1;
	int x2;
	int y1;
	int y2;

	if (x_1 > x_2)
	{
		x1 = x_2;
		x2 = x_1;
		y1 = y_2;
		y2 = y_1;
	}
	else
	{
		x1 = x_1;
		x2 = x_2;
		y1 = y_1;
		y2 = y_2;
	}
	while (x1 <= x2)
	{
		put_pixel(all, x1, y1, 0xffffff);
		put_pixel(all, x1, y2, 0xffffff);
		x1++;
	}
	if (y_1 > y_2)
	{
		x1 = x_2;
		x2 = x_1;
		y1 = y_2;
		y2 = y_1;
	}
	else
	{
		x1 = x_1;
		x2 = x_2;
		y1 = y_1;
		y2 = y_2;
	}
	while (y1 <= y2)
	{
		put_pixel(all, x1, y1, 0xffffff);
		put_pixel(all, x2, y1, 0xffffff);
		y1++;
	}
}

static void	draw_serp(t_mlx *all, double x1, double y1, double x2, double y2, int n)
{
    if (n > 0)
    {
        double new_x1 = 2 * x1 / 3 + x2 / 3 + all->center_x;
        double new_x2 = x1 / 3 + 2 * x2 / 3 + all->center_x;
        double new_y1 = 2 * y1 / 3 + y2 / 3 + all->center_y;
        double new_y2 = y1 / 3 + 2 * y2 / 3 + all->center_y;

        rectangle(all, (int)new_x1, (int)new_y1, (int)new_x2, (int)new_y2);
        draw_serp(all, x1, y1, new_x1, new_y1, n-1);
        draw_serp(all, new_x1, y1, new_x2, new_y1, n-1);
        draw_serp(all, new_x2, y1, x2, new_y1, n-1);
        draw_serp(all, x1, new_y1, new_x1, new_y2, n-1);
        draw_serp(all, new_x2, new_y1, x2, new_y2, n-1);
        draw_serp(all, x1, new_y2, new_x1, y2, n-1);
        draw_serp(all, new_x1, new_y2, new_x2, y2, n-1);
        draw_serp(all, new_x2, new_y2, x2, y2, n-1);
    }
}

void	serp(t_mlx *all)
{
	int i;

	i = -1;
	while (++i < WIN_X * WIN_Y * 4)
		all->map[i] = 0x000000;
	draw_serp(all, 0, 0, WIN_X - 1, WIN_Y - 1, all->max_iter);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}
