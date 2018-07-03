/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 14:10:55 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/16 14:10:56 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_lines(t_mlx *all, int x_1, int y_1, int x_2, int y_2)
{
	int x1;
	int x2;
	int y1;
	int y2;
	int d;
	int x;
	int y;

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
	x = x1;
	y = y1;
	if (abs_int(x2 - x1) > abs_int(y2 - y1))
	{
		while (x <= x2)
		{
			y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);
			put_pixel(all, (int)x, (int)y, 0xffffff);
			x++;;
		}
	}
	else
	{
		d = y2 > y1 ? 1 : -1;
		while (d * y <= d * y2)
		{
			x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
			put_pixel(all, (int)x, (int)y, 0xffffff);
			y += d;
		}
	}
}

static void	draw_koch(t_mlx *all, double x1, double y1, double x2, double y2, int i)
{
	double xd, yd, xb, yb, xc, yc, cos60, sin60;

	if (i == 0)
	{
		draw_lines(all, x1, y1, x2, y2);
	}
	else
	{
		xb = x1 + (x2 - x1) * 1/3;
		yb = y1 + (y2 - y1) * 1/3;

		xd = x1 + (x2 - x1) * 2/3;
		yd = y1 + (y2 - y1) * 2/3;

		cos60 = 0.5;
		sin60 = -0.866;
		xc = xb + (xd - xb) * cos60 - sin60 * (yd - yb);
		yc = yb + (xd - xb) * sin60 + cos60 * (yd - yb);

		draw_koch(all, x1, y1, xb, yb, i - 1);
		draw_koch(all, xb, yb, xc, yc, i - 1);
		draw_koch(all, xc, yc, xd, yd, i - 1);
		draw_koch(all, xd, yd, x2, y2, i - 1);
	}
}

void	koch(t_mlx *all)
{
	int i;

	i = -1;
	while (++i < WIN_X * WIN_Y * 4)
		all->map[i] = 0x000000;
	draw_koch(all, 0, WIN_Y - 200, WIN_X - 1, WIN_Y - 200, all->max_iter);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}
