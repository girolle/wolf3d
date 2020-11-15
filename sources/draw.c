/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:07:16 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/14 23:11:14 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		find_id(t_wolf *e)
{
	if (e->ray.hit_side == 1)
	{
		if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
			(e->ray.step.x == 1 && e->ray.step.y == -1))
			return (1);
		if ((e->ray.step.x == -1 && e->ray.step.y == 1) ||
			(e->ray.step.x == 1 && e->ray.step.y == 1))
			return (2);
	}
	if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
		(e->ray.step.x == -1 && e->ray.step.y == 1))
		return (3);
	return (4);
}

void	put_pxl_to_img(t_wolf *e, int x, int y, int lineheight)
{
	if (x < WIDTH && y < HEIGHT)
	{
		e->text.y = abs((((y * 256 - HEIGHT * 128 + lineheight * 128) * 64)
					/ lineheight) / 256);
		if (!(ft_memcpy(e->mlx.pxl + 4 * WIDTH * y + x * 4,
				&e->texture[find_id(e)].data[e->text.y % 64 * 64 * 4 +
				e->text.x % 64 * e->texture[find_id(e)].bpp / 8], sizeof(int))))
			error_er();
	}
}

void	draw_wall(int x, int start, int end, t_env *e)
{
	double	wall;
	int		lineheight;

	lineheight = (int)(e->height / e->ray.dist);
	if (e->ray.hit_side == 0)
		wall = e->ray.pos.y + e->ray.dist * e->ray.dir.y;
	else
		wall = e->ray.pos.x + e->ray.dist * e->ray.dir.x;
	wall -= floor((wall));
	e->text.x = (int)(wall * (double)(64));
	if (e->ray.hit_side == 0 && e->ray.dir.x > 0)
		e->text.x = 64 - e->text.x - 1;
	if (e->ray.hit_side == 1 && e->ray.dir.y < 0)
		e->text.x = 64 - e->text.x - 1;
	e->text.x = abs(e->text.x);
	while (++start <= end)
	{
		put_pxl_to_img(e, x, start, lineheight);
	}
}

void	draw_sky(t_env *e)
{
	e->text.x = 0;
	while (e->text.x < WIDTH)
	{
		e->text.y = 0;
		while (e->text.y < HEIGHT / 2)
		{
			if (!(ft_memcpy(e->mlx.pxl + 4 * WIDTH * e->text.y + e->text.x * 4,
				&e->texture[0].data[e->text.y % 512 *
					e->texture[0].sizeline + e->text.x % 512 *
					e->texture[0].bpp / 8], sizeof(int))))
				error_er();
			e->text.y++;
		}
		e->text.x++;
	}
}

void	draw_floor(t_env *e, int end, int x)
{
	int color;
	int y;

	color = 0x333333;
	if (end > 0)
	{
		y = end - 1;
		if (x < WIDTH && y < HEIGHT)
			while (++y < HEIGHT)
				if (!(ft_memcpy(e->mlx.pxl + 4 * WIDTH * y + x * 4,
						&color, sizeof(int))))
					error_er();
	}
}
