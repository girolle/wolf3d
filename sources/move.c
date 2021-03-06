/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:11:25 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/15 18:12:19 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	move_up(t_wolf *e)
{
	if (e->map[(int)(e->player.pos.x + e->player.dir.x * 10 *
	e->player.speed_move)][(int)e->player.pos.y] == 0)
		e->player.pos.x += e->player.dir.x * e->player.speed_move;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y +
	e->player.dir.y * 10 * e->player.speed_move)] == 0)
		e->player.pos.y += e->player.dir.y * e->player.speed_move;
}

void	move_down(t_wolf *e)
{
	if (e->map[(int)(e->player.pos.x - e->player.dir.x * 2 *
	e->player.speed_move)][(int)e->player.pos.y] == 0)
		e->player.pos.x -= e->player.dir.x * e->player.speed_move;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y -
	e->player.dir.y * 2 * e->player.speed_move)] == 0)
		e->player.pos.y -= e->player.dir.y * e->player.speed_move;
}

void	move_right(t_wolf *e)
{
	t_dxy	old;

	old.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(-e->player.speed_turn) -
		e->player.dir.y * sin(-e->player.speed_turn);
	e->player.dir.y = old.x * sin(-e->player.speed_turn) + e->player.dir.y *
		cos(-e->player.speed_turn);
	old.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(-e->player.speed_turn) -
		e->player.plane.y * sin(-e->player.speed_turn);
	e->player.plane.y = old.x * sin(-e->player.speed_turn) + e->player.plane.y *
		cos(-e->player.speed_turn);
}

void	move_left(t_wolf *e)
{
	t_dxy	old;

	old.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(e->player.speed_turn) -
		e->player.dir.y * sin(e->player.speed_turn);
	e->player.dir.y = old.x * sin(e->player.speed_turn) + e->player.dir.y *
		cos(e->player.speed_turn);
	old.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(e->player.speed_turn) -
		e->player.plane.y * sin(e->player.speed_turn);
	e->player.plane.y = old.x * sin(e->player.speed_turn) + e->player.plane.y *
		cos(e->player.speed_turn);
}
