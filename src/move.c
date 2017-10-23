/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:07:29 by pabonnin          #+#    #+#             */
/*   Updated: 2017/10/21 17:01:12 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_up(t_env *e)
{
	if (map((int)(e->pos_x + e->dir_x * e->movespeed), (int)e->pos_y) == 0)
		e->pos_x += e->dir_x * e->movespeed;
	if (map((int)e->pos_x, (int)(e->pos_y + e->dir_y * e->movespeed)) == 0)
		e->pos_y += e->dir_y * e->movespeed;
	ft_draw_o_redraw(e);
}

void		move_back(t_env *e)
{
	if (map((int)(e->pos_x - e->dir_x * e->movespeed), (int)e->pos_y) == 0)
		e->pos_x -= e->dir_x * e->movespeed;
	if (map((int)e->pos_x, (int)(e->pos_y - e->dir_y * e->movespeed)) == 0)
		e->pos_y -= e->dir_y * e->movespeed;
	ft_draw_o_redraw(e);
}

void		move_right(t_env *e)
{
	double olddir_x;
	double oldplane_x;

	olddir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(-(e->rotspeed)) - e->dir_y * sin(-(e->rotspeed));
	e->dir_y = olddir_x * sin(-(e->rotspeed)) + e->dir_y * cos(-(e->rotspeed));
	oldplane_x = e->plane_x;
	e->plane_x = e->plane_x * cos(-(e->rotspeed)) -
		e->plane_y * sin(-(e->rotspeed));
	e->plane_y = oldplane_x * sin(-(e->rotspeed)) +
		e->plane_y * cos(-(e->rotspeed));
	ft_draw_o_redraw(e);
}

void		move_left(t_env *e)
{
	double olddir_x;
	double oldplane_x;

	olddir_x = e->dir_x;
	e->dir_x = e->dir_x * cos(e->rotspeed) - e->dir_y * sin(e->rotspeed);
	e->dir_y = olddir_x * sin(e->rotspeed) + e->dir_y * cos(e->rotspeed);
	oldplane_x = e->plane_x;
	e->plane_x = e->plane_x * cos(e->rotspeed) - e->plane_y * sin(e->rotspeed);
	e->plane_y = oldplane_x * sin(e->rotspeed) + e->plane_y * cos(e->rotspeed);
	ft_draw_o_redraw(e);
}
