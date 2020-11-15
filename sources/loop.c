/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:09:54 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/15 18:20:31 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	print_menu(t_wolf *e)
{
	int		y;
	int		x;

	y = 0;
	x = WIDTH - 200;
	mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 190, y += 20,
				0xEAEAEA, "Move: arrows W S");
	mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 190, y += 30,
				0xEAEAEA, "Rotate: arrows A D");
	mlx_string_put(e->mlx.mlx, e->mlx.win, WIDTH - 190, y += 30,
				0xEAEAEA, "Exit: esc");
	y = 0;
	while (y <= 150)
	{
		mlx_pixel_put(e->mlx.mlx, e->mlx.win, WIDTH - 200, y, 0xEAEAEA);
		mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, 150, 0xEAEAEA);
		y++;
		x++;
	}
	while (x <= WIDTH)
	{
		mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, 150, 0xEAEAEA);
		x++;
	}
}

int		loop_hook(t_wolf *e)
{
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
	print_menu(e);
	draw_map(e);
	draw_player(e);
	return (0);
}
