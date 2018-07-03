/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:14:13 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/11 18:14:15 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		next_2(int i, unsigned int *color)
{
	if (i % 16 < 2)
		*color = 0x0000ff;
	else if (i % 16 < 4)
		*color = 0x00ff00;
	else if (i % 16 < 6)
		*color = 0xff0000;
	else if (i % 16 < 8)
		*color = 0x0000ff;
	else if (i % 16 < 10)
		*color = 0x00ff00;
	else if (i % 16 < 12)
		*color = 0xff0000;
	else if (i % 16 < 14)
		*color = 0x0000ff;
	else
		*color = 0x00ff00;
}

static void		next_1(int max_iter, int i, unsigned int *color)
{
	*color = 0x000000;
	if (i < max_iter)
	{
		*color = i % 16 << 20 | i % 16 << 16 | i % 16 << 12 | i % 16 << 8
				| i % 16 << 4 | i % 16;
		if (i < (max_iter / 2 - 1))
			*color = (i % 16 << 12 | i % 16 << 8) & 0x00ff00;
	}
}

unsigned int	determ_color(int max_iter, int i, int psycho)
{
	unsigned int	color;

	color = 0x000000;
	if (abs_int(psycho % 4) == 0 || abs_int(psycho % 4) == 1)
	{
		if (i < max_iter)
		{
			color = i % 16 << 20 | i % 16 << 16 | i % 16 << 12 | i % 16 << 8
					| i % 16 << 4 | i % 16;
			if (i < (max_iter / 2 - 1) && abs_int(psycho % 4) == 0)
				color = (i % 16 << 20 | i % 16 << 16) & 0xff0000;
			else if (i < (max_iter / 2 - 1))
				color = (i % 16 << 4 | i % 16) & 0x0000ff;
		}
	}
	else if (abs_int(psycho % 4) == 2)
		next_1(max_iter, i, &color);
	else
		next_2(i, &color);
	return (color);
}
