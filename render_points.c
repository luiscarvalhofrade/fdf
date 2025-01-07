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

int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

int handle_keypress(int keycode, t_data *data) {
    if (keycode == 65307) {  // ESC key
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit(0);
    }
    else if (keycode == 65361)  // Left arrow
        printf("Left arrow pressed!\n");
    else if (keycode == 65363)  // Right arrow
        printf("Right arrow pressed!\n");
    else if (keycode == 65362)  // Up arrow
        printf("Up arrow pressed!\n");
    else if (keycode == 65364)  // Down arrow
        printf("Down arrow pressed!\n");
    return (0);
}

int	render_points(int **matrix, int rows, int cols)
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, SC_WIDTH, SC_HEIGHT, "Iso View");
	data.img = mlx_new_image(data.mlx, SC_WIDTH, SC_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
			&data.line_length, &data.endian);
	draw_points_and_lines(rows, cols, matrix, data);
	free_matrix(matrix, rows);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.mlx_win, 17, 0L, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
