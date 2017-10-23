/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:13:31 by pabonnin          #+#    #+#             */
/*   Updated: 2017/10/21 17:43:45 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		color_set(t_env *e, int side)
{
	if (side == 0 && e->step_x < 0)
		return (2);
	else if (side == 0 && e->step_x >= 0)
		return (3);
	else if (side == 1 && e->step_y < 0)
		return (4);
	else if (side == 1 && e->step_y >= 0)
		return (5);
	return (0);
}

void	fill_pixel2(t_env *e, int color, int i)
{
	if (color == 3)
	{
		e->data[i] = (char)14;
		e->data[i + 1] = (char)102;
		e->data[i + 2] = (char)21;
	}
	else if (color == 4)
	{
		e->data[i] = (char)15;
		e->data[i + 1] = (char)101;
		e->data[i + 2] = (char)187;
	}
	else if (color == 5)
	{
		e->data[i] = (char)0;
		e->data[i + 1] = (char)150;
		e->data[i + 2] = (char)75;
	}
}

void	fill_pixel(t_env *e, int y, int x, int color)
{
	int		i;

	i = (x * 4) + (y * e->s_l);
	if (color == 1)
	{
		e->data[i] = (char)17;
		e->data[i + 1] = (char)52;
		e->data[i + 2] = (char)112;
	}
	else if (color == 2)
	{
		e->data[i] = (char)9;
		e->data[i + 1] = (char)250;
		e->data[i + 2] = (char)40;
	}
	else if (color == 3 || color == 4 || color == 5)
		fill_pixel2(e, color, i);
}

void	color_wall(t_env *e, int x)
{
	int		i;

	i = e->draw_s;
	while (i++ != e->draw_e && i < HEIGHT)
		fill_pixel(e, i, x, color_set(e, e->side));
	while (i < HEIGHT)
		fill_pixel(e, i++, x, 1);
}
