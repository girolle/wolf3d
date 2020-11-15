/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:09:18 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/15 18:12:19 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		x_close(void *data)
{
	(void)data;
	exit(0);
}

void	key_move(int k, t_wolf *e)
{
	if (k == KEY_UP || k == KEY_UP_W)
		e->player.move_up = !e->player.move_up;
	if (k == KEY_DOWN || k == KEY_LEFT_S)
		e->player.move_down = !e->player.move_down;
	if (k == KEY_LEFT || k == KEY_DOWN_A)
		e->player.move_left = !e->player.move_left;
	if (k == KEY_RIGHT || k == KEY_RIGHT_D)
		e->player.move_right = !e->player.move_right;
	if (k == KEY_ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
}

int		key_hook(int k, t_wolf *e)
{
	key_move(k, e);
	return (0);
}
