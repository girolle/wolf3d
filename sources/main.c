/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:10:51 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/01 14:10:59 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		read_option(t_env *e, int argc, char **argv)
{
	if (argc != 2)
		error_arg();
	if (open_file(e, argv[1]) == 0)
		error_map();
}

int				main(int argc, char **argv)
{
	t_env	*e;

	e = init_env();
	read_option(e, argc, argv);
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT,
			"Wolf3d");
	mlx_do_key_autorepeatoff(e->mlx.mlx);
	mlx_loop_hook(e->mlx.mlx, loop_hook, e);
	mlx_hook(e->mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_hook, e);
	mlx_key_hook(e->mlx.win, key_hook, e);
	mlx_loop(e->mlx.mlx);
	return (0);
}
