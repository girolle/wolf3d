/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:12:40 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/09 21:06:57 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		read_pos(int fd, t_env *e)
{
	char	*line;
	char	**line_split;
	int		i;

	i = -1;
	if (get_next_line(fd, &line) < 1)
		error_map();
	line_split = ft_strsplit(line, ' ');
	while (line_split[++i] != '\0')
		;
	if (i != 2)
		error_map();

	e->player.pos.x = ft_atoi(line_split[0]) + 0.5;
	e->player.pos.y = ft_atoi(line_split[1]) + 0.5;
}

static int		read_file(int fd, t_env *e)
{
	char	*line;
	int		y;
	int		**map;
	int		i;

	y = -1;
	if  (!(map = (int **)malloc(sizeof(int **) * e->map_height)))
			return (0);
	i = 0;
	get_next_line(fd, &line);
	while (get_next_line(fd, &line))
	{
		map[i++] = ft_num_split(line);
		ft_strdel(&line);
	}
	if (map[(int)e->player.pos.x][(int)e->player.pos.y] != 0)
		error_map();
	e->map = map;
	return (1);
}

int				open_file(t_env *e, char *f)
{
	int		fd;
	char	*line;
	int		width_curr;

	fd = open(f, O_DIRECTORY); //Зачем это?
	if (fd >= 0)
		return (0);
	fd = open(f, O_RDONLY);
	if (fd < 0)
		return (0);
	read_pos(fd, e);
	e->map_width = -1;
	e->map_height = 0;

	while (get_next_line(fd, &line))
	{
		e->map_height++;
		if (e->map_width < 0)
			e->map_width = ft_num_ammount(line);
		width_curr = ft_num_ammount(line);
		ft_strdel(&line);
		if (((e->map_width) != width_curr) || (!(width_curr > 0)))
			error_map();
	}
	close(fd);
		if (e->map_width < 0 || e->map_height < 0 || e->player.pos.x < 0 ||
			e->player.pos.y < 0 || e->player.pos.x >= e->map_width ||
			e->player.pos.y >= e->map_width)
						error_map();

	fd = open(f, O_RDONLY);
	return (read_file(fd, e));
}


