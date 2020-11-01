/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:09:18 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/01 14:09:26 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	key_move(int k, t_env *e)
{
	if (k == KEY_UP)
		e->player.move_up = !e->player.move_up;
	if (k == KEY_DOWN)
		e->player.move_down = !e->player.move_down;
	if (k == KEY_LEFT)
		e->player.move_left = !e->player.move_left;
	if (k == KEY_RIGHT)
		e->player.move_right = !e->player.move_right;
	if (k == KEY_ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
}

int		key_hook(int k, t_env *e)
{
	key_move(k, e);
	return (0);
}
