/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:10:51 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/15 18:20:11 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			textures_sky(t_wolf *e)
{
	int	h1;
	int	w1;

	h1 = 600;
	w1 = 800;
	e->texture[0].image = mlx_xpm_file_to_image(e->mlx.mlx,
		"pics/stars1.xpm", &h1, &w1);
	e->texture[0].data = mlx_get_data_addr(e->texture[0].image,
		&e->texture[0].bpp, &e->texture[0].sizeline, &e->texture[0].endian);
}

void			textures(t_wolf *e)
{
	int	h;
	int	w;

	h = 64;
	w = 64;
	e->texture[1].image = mlx_xpm_file_to_image(e->mlx.mlx, "pics/mossy.xpm",
		&h, &w);
	e->texture[1].data = mlx_get_data_addr(e->texture[1].image,
		&e->texture[1].bpp, &e->texture[1].sizeline, &e->texture[1].endian);
	e->texture[2].image = mlx_xpm_file_to_image(e->mlx.mlx, "pics/wood.xpm",
		&h, &w);
	e->texture[2].data = mlx_get_data_addr(e->texture[2].image,
		&e->texture[2].bpp, &e->texture[2].sizeline, &e->texture[2].endian);
	e->texture[3].image = mlx_xpm_file_to_image(e->mlx.mlx, "pics/redbrick.xpm",
		&h, &w);
	e->texture[3].data = mlx_get_data_addr(e->texture[3].image,
		&e->texture[3].bpp, &e->texture[3].sizeline, &e->texture[3].endian);
	e->texture[4].image = mlx_xpm_file_to_image(e->mlx.mlx,
		"pics/purplestone.xpm", &h, &w);
	e->texture[4].data = mlx_get_data_addr(e->texture[4].image,
		&e->texture[4].bpp, &e->texture[4].sizeline, &e->texture[4].endian);
}

static void		read_option(t_wolf *e, int argc, char **argv)
{
	if (argc != 2)
		error_arg();
	if (open_file(e, argv[1]) == 0)
		error_map();
}

int				main(int argc, char **argv)
{
	t_wolf	*e;

	e = init_wolf();
	textures(e);
	textures_sky(e);
	read_option(e, argc, argv);
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT,
			"Wolf3d");
	mlx_do_key_autorepeatoff(e->mlx.mlx);
	mlx_loop_hook(e->mlx.mlx, loop_hook, e);
	mlx_hook(e->mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_hook, e);
	mlx_hook(e->mlx.win, KEY_PRESS_X, KEY_PRESS_MASK, x_close, e);
	mlx_key_hook(e->mlx.win, key_hook, e);
	mlx_loop(e->mlx.mlx);
	return (0);
}
