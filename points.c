#include "fdf.h"

t_2d_pt	isometric_projection(t_3d_pt point)
{
	t_2d_pt	projected;

	point.x = point.x * 10;
	point.y = point.y * 10;
	point.z = point.z * 10;
	projected.x = (int)((point.x - point.y) * cos(M_PI / 6));
	projected.y = (int)((point.x + point.y) * sin(M_PI / 6) - point.z);
	projected.x = projected.x + SCREEN_WIDTH / 2;
	projected.y = projected.y + SCREEN_HEIGHT / 3;
	return (projected);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham_line(t_data *img, t_2d_pt start, t_2d_pt end, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(end.x - start.x);
	dy = abs(end.y - start.y);
	if (start.x < end.x)
		sx = 1;
	else
		sx = -1;
	if (start.y < end.y)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	while (1)
	{
		my_mlx_pixel_put(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			start.x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			start.y += sy;
		}
	}
}
