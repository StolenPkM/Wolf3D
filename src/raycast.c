/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:08:08 by pabonnin          #+#    #+#             */
/*   Updated: 2017/10/21 16:55:54 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		fish_corr(t_env *e)
{
	e->line_h = (int)(e->height / e->walldist);
	e->draw_s = (-(e->line_h) / 2) + (e->height / 2);
	if (e->draw_s < 0)
		e->draw_s = 0;
	e->draw_e = (e->line_h / 2) + (e->height / 2);
	if (e->draw_e >= (e->height - 1))
		e->draw_e = (e->height - 1);
}

void		perf_dda(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->sidedist_x < e->sidedist_y)
		{
			e->sidedist_x += e->deltadist_x;
			e->map_x += e->step_x;
			e->side = 0;
		}
		else
		{
			e->sidedist_y += e->deltadist_y;
			e->map_y += e->step_y;
			e->side = 1;
		}
		if (map(e->map_x, e->map_y) > 0)
			e->hit = 1;
	}
	if (e->side == 0)
		e->walldist = (e->map_x - e->raypos_x +
				(1 - e->step_x) / 2) / e->raydir_x;
	else
		e->walldist = (e->map_y - e->raypos_y +
				(1 - e->step_y) / 2) / e->raydir_y;
}

void		calc_step(t_env *e)
{
	if (e->raydir_x < 0)
	{
		e->step_x = -1;
		e->sidedist_x = (e->raypos_x - e->map_x) * e->deltadist_x;
	}
	else
	{
		e->step_x = 1;
		e->sidedist_x = (e->map_x + 1.0 - e->raypos_x) * e->deltadist_x;
	}
	if (e->raydir_y < 0)
	{
		e->step_y = -1;
		e->sidedist_y = (e->raypos_y - e->map_y) * e->deltadist_y;
	}
	else
	{
		e->step_y = 1;
		e->sidedist_y = (e->map_y + 1.0 - e->raypos_y) * e->deltadist_y;
	}
}

void		ray_pos_dir(t_env *e, int x)
{
	e->camera_x = 2 * x / (double)e->width - 1;
	e->raypos_x = e->pos_x;
	e->raypos_y = e->pos_y;
	e->raydir_x = e->dir_x + e->plane_x * e->camera_x;
	e->raydir_y = e->dir_y + e->plane_y * e->camera_x;
	e->map_x = (int)e->raypos_x;
	e->map_y = (int)e->raypos_y;
	e->sidedist_x = 0;
	e->sidedist_y = 0;
	e->deltadist_x = 0;
	e->deltadist_y = 0;
	e->deltadist_x = sqrt(1 + (e->raydir_y * e->raydir_y) /
			(e->raydir_x * e->raydir_x));
	e->deltadist_y = sqrt(1 + (e->raydir_x * e->raydir_x) /
			(e->raydir_y * e->raydir_y));
	e->step_x = 0;
	e->step_y = 0;
	e->walldist = 0;
	e->hit = 0;
	e->side = 0;
}

void		raycasting(t_env *e)
{
	int		x;

	x = 0;
	while (x < e->width)
	{
		ray_pos_dir(e, x);
		calc_step(e);
		perf_dda(e);
		fish_corr(e);
		color_wall(e, x);
		x++;
	}
}
