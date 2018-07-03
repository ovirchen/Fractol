/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:24:57 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/12 17:24:59 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel(t_mlx *all, int x, int y, unsigned int c)
{
	int	i;

	i = y * all->size_line + x * 4;
	if (i >= 0 && i < WIN_X * WIN_Y * 4)
	{
		all->map[i] = c;
		all->map[++i] = c >> 8;
		all->map[++i] = c >> 16;
	}
}

void		put_set(t_mlx *all, t_set *c, int x, int y)
{
	int	i;

	i = -1;
	while (++i < all->max_iter)
	{
		c->old_re = c->new_re;
		c->old_im = c->new_im;
		c->new_re = c->old_re * c->old_re - c->old_im * c->old_im + c->re;
		c->new_im = 2 * c->old_re * c->old_im + c->im;
		if ((c->new_re * c->new_re + c->new_im * c->new_im) > 4)
			break ;
	}
	put_pixel(all, x, y, determ_color(all->max_iter, i, all->psycho));
}

void		put_set_burn(t_mlx *all, t_set *c, int x, int y)
{
	int	i;

	i = -1;
	while (++i < all->max_iter)
	{
		c->old_re = c->new_re;
		c->old_im = c->new_im;
		c->new_re = abs_double(c->old_re * c->old_re - c->old_im
			* c->old_im + c->re);
		c->new_im = abs_double(2 * c->old_re * c->old_im) + c->im;
		if ((c->new_re * c->new_re + c->new_im * c->new_im) > 4)
			break ;
	}
	put_pixel(all, x, y, determ_color(all->max_iter, i, all->psycho));
}

void		put_set_heart(t_mlx *all, t_set *c, int x, int y)
{
	int	i;

	i = -1;
	while (++i < all->max_iter)
	{
		c->old_re = c->new_re;
		c->old_im = c->new_im;
		c->new_re = c->old_re * c->old_re - c->old_im * c->old_im + c->re;
		c->new_im = 2 * abs_double(c->old_re) * c->old_im + c->im;
		if ((c->new_re * c->new_re + c->new_im * c->new_im) > 4)
			break ;
	}
	put_pixel(all, x, y, determ_color(all->max_iter, i, all->psycho));
}
