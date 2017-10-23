/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:49:59 by pabonnin          #+#    #+#             */
/*   Updated: 2017/10/21 17:17:46 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 800
# define HEIGHT 800

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			s_l;
	int			endian;
	int			check;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raypos_x;
	double		raypos_y;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		walldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			draw_s;
	int			draw_e;
	double		frametime;
	double		movespeed;
	double		rotspeed;
	int			height;
	int			width;
}				t_env;

int				map(int x, int y);
void			map_init();
void			mlxinit(t_env *e);
void			player_init(t_env *e);
void			raycasting(t_env *e);
void			ray_pos_dir(t_env *e, int x);
void			calc_step(t_env *e);
void			perf_dda(t_env *e);
void			fish_corr(t_env *e);
void			fill_pixel(t_env *e, int y, int x, int color);
void			color_wall(t_env *e, int x);
void			ft_draw_o_redraw(t_env *e);
void			ft_loop(t_env *e);
int				quit(t_env *e);
int				restart(t_env *e);
int				ft_key_hook(int key, t_env *e);
int				ft_key_release(int key, t_env *e);
void			move_up(t_env *e);
void			move_back(t_env *e);
void			move_right(t_env *e);
void			move_left(t_env *e);

#endif
