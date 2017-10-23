/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:43:10 by pabonnin          #+#    #+#             */
/*   Updated: 2017/10/21 19:05:38 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		restart(t_env *e)
{
	player_init(e);
	ft_draw_o_redraw(e);
	return (1);
}

int		quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
	return (1);
}

int		ft_key_hook(int key, t_env *e)
{
	(key == 53) ? quit(e) : 0;
	(key == 13 || key == 126) ? move_up(e) : 0;
	(key == 0 || key == 123) ? move_left(e) : 0;
	(key == 1 || key == 125) ? move_back(e) : 0;
	(key == 2 || key == 124) ? move_right(e) : 0;
	(key == 15) ? restart(e) : 0;
	return (1);
}

int		ft_key_release(int key, t_env *e)
{
	(key == 13) ? move_up(e) : 0;
	(key == 0) ? move_left(e) : 0;
	(key == 1) ? move_back(e) : 0;
	(key == 2) ? move_right(e) : 0;
	return (1);
}
