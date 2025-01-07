/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:23:15 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/07 13:23:16 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_matrix(int **matrix, int rows)
{
	int	i_row;

	i_row = 0;
	while (i_row < rows)
	{
		free(matrix[i_row]);
		i_row++;
	}
	free(matrix);
}

void	draw_points_and_lines(int rows, int cols, int **matrix, t_data img)
{
	int		y;
	int		x;
	t_3d_pt	point3d_start;
	t_3d_pt	point3d_end;
	t_2d_pt	start;
	t_2d_pt	end;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			point3d_start.x = x;
			point3d_start.y = y;
			point3d_start.z = matrix[y][x];
			if (x + 1 < cols)
			{
				point3d_end.x = x + 1;
				point3d_end.y = y;
				point3d_end.z = matrix[y][x + 1];
				start = iso_proj(point3d_start);
				end = iso_proj(point3d_end);
				bresenham_line(&img, start, end, 0x00FF0000);
			}
			if (y + 1 < rows)
			{
				point3d_end.x = x;
				point3d_end.y = y + 1;
				point3d_end.z = matrix[y + 1][x];
				start = iso_proj(point3d_start);
				end = iso_proj(point3d_end);
				bresenham_line(&img, start, end, 0x00FF0000);
			}
			x++;
		}
		y++;
	}
}

int	render_points(int **matrix, int rows, int cols)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SC_WIDTH, SC_HEIGHT, "Isometric View");
	img.img = mlx_new_image(mlx, SC_WIDTH, SC_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	draw_points_and_lines(rows, cols, matrix, img);
	free_matrix(matrix, rows);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
