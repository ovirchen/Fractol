/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:14:15 by ovirchen          #+#    #+#             */
/*   Updated: 2018/06/06 16:14:16 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

# define WIN_X 1450
# define WIN_Y 920
# define MV 0.05
# define DEPTH 1000
# define THRDS 8

typedef struct	s_set
{
	double	re;
	double	im;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
}				t_set;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*name;
	double	center_x;
	double	center_y;
	double	re_max;
	double	re_min;
	double	im_max;
	double	im_min;
	double	zoom;
	int		bit_per_pxl;
	int		size_line;
	int		endian;
	char	*map;
	int		max_iter;
	int		psycho;
	int		lock;
	double	mouse_x;
	double	mouse_y;
	void	(*f)(struct	s_mlx *all);
}				t_mlx;

typedef struct	s_thrd
{
	t_mlx	*all;
	int		num_thrd;
}				t_thrd;

int				ft_error(void);
int				ft_usage(void);
int				exit_x();
int				my_key_funct(int keycode, t_mlx *all);

void			init(t_mlx *all);
int				init_function(char *filename, t_mlx *all);
void			win_text(t_mlx *all);

void			mandelbrot(t_mlx *all);
void			julia(t_mlx *all);
void			burningship(t_mlx *all);
void			heart(t_mlx *all);

void			put_pixel(t_mlx *all, int x, int y, unsigned int c);
void			put_set(t_mlx *all, t_set *c, int x, int y);
void			put_set_burn(t_mlx *all, t_set *c, int x, int y);
void			put_set_heart(t_mlx *all, t_set *c, int x, int y);
unsigned int	determ_color(int max_iter, int i, int psycho);

void			move_map_left(t_mlx *all);
void			move_map_right(t_mlx *all);
void			move_map_up(t_mlx *all);
void			move_map_down(t_mlx *all);

void			zoom_plus(t_mlx *all);
void			zoom_minus(t_mlx *all);

int				mouse_hook(int x, int y, t_mlx *all);
int				mouse_scroll(int button, int x, int y, t_mlx *all);

#endif
