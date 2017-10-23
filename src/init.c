/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 19:24:38 by pabonnin          #+#    #+#             */
/*   Updated: 2017/10/23 14:54:30 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		mlxinit(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Wolf3d @pabonnin");
	e->bpp = 0;
	e->s_l = 0;
	e->width = WIDTH;
	e->height = HEIGHT;
}

void		player_init(t_env *e)
{
	e->pos_x = 2.0;
	e->pos_y = 18.0;
	e->dir_x = -1.00001;
	e->dir_y = 0.00001;
	e->plane_x = 0.;
	e->plane_y = 0.66;
	e->map_x = 0;
	e->map_y = 0;
	e->movespeed = 0.2;
	e->rotspeed = 0.1;
}
