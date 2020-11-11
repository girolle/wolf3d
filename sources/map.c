#include "../includes/wolf.h"

// TODO доделать направление игрока на карте
//void 	draw_dir(int x, int y, t_env *e, int color)
//{
//	int i;
//	int j;
//
//	i = 0;
//	j = 0;
//	if(e->player.dir.x < 0 && e->player.dir.y <= 0)
//	{
//		x++;
//		y--;
//		while(j++ < 10)
//		{
//			while(i++ < 4)
//			{
//				mlx_pixel_put(e->mlx.mlx, e->mlx.win, x++, y,
//							  color);
//			}
//			i = 0;
//			y--;
//			x -= 4;
//		}
//
//	}
//}

void 	draw_square(int x, int y, t_env *e, int color)
{
	int y1;
	int x1;

	y1 = y;
	x1 = x;
	while (y <= y1 + 5)
	{
		while (x <= x1 + 5)
		{
			mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y,
						  color);
			x++;
		}
		y++;
		x = x1;
	}
}

void	draw_player(t_env *e)
{
	int 	x;
	int		y;

	x = (int)e->player.pos.x * 5 + 5;
	y = (int)e->player.pos.y * 5 + 5;
	draw_square(y, x, e, 0x00FF00);
	//draw_dir(y, x, e, 0xFF0000);
}

void	draw_map(t_env *e)
{
	int x;
	int y;
	int i;
	int j;

	x = 5;
	y = 5;
	i = 0;
	j = 0;
	while(i < e->map_height)
	{
		while (j < e->map_width)
		{
			if (e->map[i][j] == 1)
				draw_square(x, y, e, 0xFFFF0F);
			j++;
			x += 5;
		}
		x = 5;
		j = 0;
		i++;
		y += 5;
	}
}