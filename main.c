/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:11:53 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/06 16:11:54 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_error(void)
{
	write(1, "error\n", 6);
	return (1);
}

int		ft_usage(void)
{
	ft_putstr("Usage : ./fractol <filename>\nFilename :\
		\n - Mandelbrot\n - Julia\n - BurningShip\n - Heart\n");
	return (1);
}

int		exit_x(void)
{
	exit(1);
	return (0);
}

void	win_text(t_mlx *all)
{
	mlx_string_put(all->mlx, all->win, 50, 50, 0x00fff2, "HOW TO USE");
	mlx_string_put(all->mlx, all->win, 50, 80, 0x00e8ff,
		"Move: A W D S and arrows");
	mlx_string_put(all->mlx, all->win, 50, 100, 0x00ccff, "Zoom: + -");
	mlx_string_put(all->mlx, all->win, 50, 130, 0x00acff, "Change color: 1 2");
	mlx_string_put(all->mlx, all->win, 50, 160, 0x008cff, "Stop mouse: space");
	mlx_string_put(all->mlx, all->win, 50, 180, 0x006cff, "Mouse zoom: scroll");
	mlx_string_put(all->mlx, all->win, 50, 210, 0x004cff,
		"Change iterations:");
	mlx_string_put(all->mlx, all->win, 50, 230, 0x003cff,
		"        sloping arrows");
	mlx_string_put(all->mlx, all->win, 50, 250, 0x002cff,
		"Default image: enter");
	mlx_string_put(all->mlx, all->win, 50, 280, 0xff000b, "Exit: Esc");
	if (abs(all->psycho % 4) == 3)
		mlx_string_put(all->mlx, all->win, 500, 500, 0xff002b,
			"CATCH THE DRUG FRIEND!!!");
}

int		main(int ac, char **av)
{
	t_mlx	all;

	if (ac != 2)
		return (ft_usage());
	if (init_function(av[1], &all) == 1)
		return (1);
	init(&all);
	all.f(&all);
	mlx_hook(all.win, 17, 1L << 17, exit_x, 0);
	mlx_hook(all.win, 2, 5, my_key_funct, &all);
	if (all.f == julia && all.lock % 2 == 0)
		mlx_hook(all.win, 6, 0, mouse_hook, &all);
	mlx_mouse_hook(all.win, mouse_scroll, &all);
	mlx_loop(all.mlx);
	sleep(5);
	return (0);
}
