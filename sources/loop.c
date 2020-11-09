/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:09:54 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/09 21:20:27 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		loop_hook(t_env *e)
{
	e->mlx.last_frame = clock();
	if (e->mlx.next_frame > e->mlx.last_frame)
		return (0);
	e->mlx.next_frame = e->mlx.last_frame + (CLOCKS_PER_SEC / 100);
	if (e->player.move_up)
		move_up(e);
	if (e->player.move_down)
		move_down(e);
	if (e->player.move_right)
		move_right(e);
	if (e->player.move_left)
		move_left(e);
	printf("%f  %f  \n", e->player.pos.x, e->player.pos.y);
	raycasting(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	draw_map(e);
	return (0);
}
