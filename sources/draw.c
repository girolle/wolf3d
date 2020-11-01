/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:07:16 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/01 14:10:22 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/wolf.h"

void			put_pxl(t_env *e, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * e->mlx.s_line);
	e->mlx.pxl[i] = c;
	e->mlx.pxl[++i] = c >> 8;
	e->mlx.pxl[++i] = c >> 16;
}

unsigned int	get_color(t_env *e)
{
	if (e->ray.hit_side == 1)
	{
		if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
			(e->ray.step.x == 1 && e->ray.step.y == -1))
			return (e->color_1);
		if ((e->ray.step.x == -1 && e->ray.step.y == 1) ||
			(e->ray.step.x == 1 && e->ray.step.y == 1))
			return (e->color_2);
	}
	if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
		(e->ray.step.x == -1 && e->ray.step.y == 1))
		return (e->color_3);
	return (e->color_4);
}

void			draw_line(t_env *e, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	c = get_color(e);
	i = -1;
	while (++i < start)
		put_pxl(e, x, i, e->color_sky);
	i--;
	while (++i <= end && i < e->height)
		put_pxl(e, x, i, c);
	i--;

	while (++i < e->height)
		put_pxl(e, x, i, e->color_ground);
}
