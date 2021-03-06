/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rczarfun <rczarfun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:04:03 by rczarfun          #+#    #+#             */
/*   Updated: 2020/11/15 18:22:09 by rczarfun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>

# define WIDTH 800
# define HEIGHT 600

# define KEY_UP 126
# define KEY_UP_W 13
# define KEY_LEFT 123
# define KEY_LEFT_S 1
# define KEY_RIGHT 124
# define KEY_RIGHT_D 2
# define KEY_DOWN 125
# define KEY_DOWN_A 0
# define KEY_ESC 53

# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2
# define KEY_PRESS_X 17

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plane;
	double			speed_turn;
	double			speed_move;

	char			move_left;
	char			move_right;
	char			move_up;
	char			move_down;
}					t_player;

typedef struct		s_ray
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_ixy	map;
	struct s_dxy	side;
	struct s_dxy	delta;
	struct s_ixy	step;
	double			dist;
	double			cam;
	int				hit;
	int				hit_side;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_mlx;

typedef struct		s_texture
{
	void			*image;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_texture;

typedef struct		s_wolf
{
	struct s_mlx	mlx;
	t_texture		texture[5];
	struct s_player	player;
	struct s_ray	ray;
	int				height;
	int				width;
	int				**map;
	int				map_width;
	int				map_height;
	t_ixy			text;
}					t_wolf;

int					loop_hook(t_wolf *e);
int					open_file(t_wolf *e, char *f);
int					key_hook(int k, t_wolf *e);
int					x_close(void *data);
t_wolf				*init_wolf(void);
void				draw_line(t_wolf *e, int x, int start, int end);
void				raycasting(t_wolf *e);
void				move_left(t_wolf *e);
void				move_right(t_wolf *e);
void				move_up(t_wolf *e);
void				move_down(t_wolf *e);
void				error_map(void);
void				error_arg(void);
void				error_malloc(void);
void				draw_map(t_wolf *e);
void				draw_player(t_wolf *e);
void				draw_wall(int x, int start, int end, t_wolf *e);
void				draw_sky(t_wolf *e);
void				draw_floor(t_wolf *e, int end, int x);
void				error_er(void);

#endif
