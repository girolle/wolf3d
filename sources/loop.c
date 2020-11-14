/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:09:54 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/14 20:40:36 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		print_tulbar(t_env *e)
{
	int		y;
	int		x;

	y = 0;
	x = WIDTH - 200;
	mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 175, y += 20, 0xb8f581, "How to Use");
	//mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 190, y += 35, 0xEAEAEA, "Zoom: ^/-^");
	mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 190, y += 30, 0xEAEAEA, "Move: W S  Keys");
	mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 190, y += 30, 0xEAEAEA, "Rotate: <-/->");
	//mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 190, y += 30, 0xEAEAEA, "Reset: R Key");
	//mlx_string_put(e->mlx.mlx, e->mlx.win, 70, y += 35, 0xb8f581, "Projections");
	//mlx_string_put(e->mlx.mlx, e->mlx.win, 15, y += 35, 0xEAEAEA, "Change mode: M Key");
	y = 0;
	while (y <= 150)
	{
		mlx_pixel_put(e->mlx.mlx, e->mlx.win, WIDTH - 200, y, 0xEAEAEA);
		mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, 150, 0xEAEAEA);
		y++;
		x++;
	}
	while(x <= WIDTH)
	{
		mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, 150, 0xEAEAEA);
		x++;
	}
}

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

	raycasting(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	print_tulbar(e);
	draw_map(e);
	draw_player(e);
	return (0);
}
