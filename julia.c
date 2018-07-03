/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 14:14:41 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/13 14:14:42 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*julia_calc(void *a)
{
	int		x;
	int		y;
	int		y_max;
	t_set	c;
	t_thrd	*th;

	th = (t_thrd*)a;
	y_max = (th->num_thrd + 1) * WIN_Y / THRDS;
	y = th->num_thrd * WIN_Y / THRDS - 1;
	c.re = th->all->mouse_x;
	c.im = th->all->mouse_y;
	while (++y < y_max)
	{
		x = -1;
		while (++x < WIN_X)
		{
			c.new_re = 3 * (x - WIN_X / 2) /
				(th->all->zoom * WIN_X) + th->all->center_x;
			c.new_im = 2 * (y - WIN_Y / 2) /
				(th->all->zoom * WIN_Y) + th->all->center_y;
			put_set(th->all, &c, x, y);
		}
	}
	pthread_exit(0);
}

void		julia(t_mlx *all)
{
	int			i;
	pthread_t	thrds[THRDS];
	t_thrd		th[THRDS];

	i = -1;
	while (++i < THRDS)
	{
		th[i].num_thrd = i;
		th[i].all = all;
		pthread_create(&(thrds[i]), NULL,
			&julia_calc, &th[i]);
	}
	i = -1;
	while (++i < THRDS)
		pthread_join(thrds[i], NULL);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	win_text(all);
}
