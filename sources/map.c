#include "../includes/wolf.h"

//void 	pixel_map(t_env *e, int x, int y, int color)
//{
//	mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y, color);
//}

//void 	draw_x(t_env *e, int y, int i)
//{
//	int j;
//	int color_map;
//	int color_player;
//	int x1;
//
//	j = 0;
//	color_map = 0xFFFF0F;
//	color_player = 0xFFFFF0;
//	while (j < e->map_width)
//	{
//		if (e->player.pos.x == (j - 0.5) && e->player.pos.y == (i - 0.5))
//		{
//			while (y <= y1 + 5)
//			{
//				while (x <= x1 + 5)
//				{
//					mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y,
//								  0xFFFFF0);
//					x++;
//				}
//				y++;
//				x = x1;
//			}
//		}
//		else if (e->map[i][j] == 1)
//		{
//			while (y <= y1 + 5)
//			{
//				while (x <= x1 + 5)
//				{
//					mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y,
//								  0xFFFF0F);
//					x++;
//				}
//				y++;
//				x = x1;
//			}
//
//		}
//		j++;
//		x1 += 5;
//		x = x1;
//		y = y1;
//	}
//}

void	draw_map(t_env *e)
{
	int x;
	int x1;
	int y;
	int y1;
	int i;
	int j;

	x = 5;
	x1 = 5;
	y = 5;
	y1 = 5;
	i = 0;
	j = 0;
	while(i < e->map_height)
	{
		while (j < e->map_width)
		{
			if (e->player.pos.x == (j - 0.5) && e->player.pos.y == (i - 0.5))
			{
				while (y <= y1 + 5)
				{
					while (x <= x1 + 5)
					{
						mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y,
									  0xFFFFF0);
						x++;
					}
					y++;
					x = x1;
				}
			}
			else if (e->map[i][j] == 1)
			{
				while (y <= y1 + 5)
				{
					while (x <= x1 + 5)
					{
						mlx_pixel_put(e->mlx.mlx, e->mlx.win, x, y,
									  0xFFFF0F);
						x++;
					}
					y++;
					x = x1;
				}

			}
			j++;
			x1 += 5;
			x = x1;
			y = y1;
		}
		x = 5;
		x1 = 5;
		j = 0;
		i++;
		y += 5;
		y1 = y;
	}
}