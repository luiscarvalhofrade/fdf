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

void	draw_pt_n_ln(t_3d_pt pt3d_start, t_3d_pt pt3d_end, t_data img, t_2d_pt (f)(t_3d_pt point))
{
	t_2d_pt	start;
	t_2d_pt	end;

	start = f(pt3d_start);
	end = f(pt3d_end);
	bresenham_line(&img, start, end, 0x00FF0000);
}

void	draw_all_pts_n_lns(t_r_c dims, int **matrix, t_data img, t_2d_pt (f)(t_3d_pt point))
{
	int		y;
	int		x;
	t_3d_pt	point3d_start;
	t_3d_pt	point3d_end;

	y = 0;
	while (y < dims.rows)
	{
		x = 0;
		while (x < dims.cols)
		{
			point3d_start.x = x;
			point3d_start.y = y;
			point3d_start.z = matrix[y][x];
			if (x + 1 < dims.cols)
			{
				point3d_end.x = x + 1;
				point3d_end.y = y;
				point3d_end.z = matrix[y][x + 1];
				draw_pt_n_ln(point3d_start, point3d_end, img, f);
			}
			if (y + 1 < dims.rows)
			{
				point3d_end.x = x;
				point3d_end.y = y + 1;
				point3d_end.z = matrix[y + 1][x];
				draw_pt_n_ln(point3d_start, point3d_end, img, f);
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

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	else if (keycode == 65361)
		printf("Right arrow pressed!\n");
	else if (keycode == 65363)
		printf("Right arrow pressed!\n");
	else if (keycode == 65362)
		printf("Up arrow pressed!\n");
	else if (keycode == 65364)
		printf("Down arrow pressed!\n");
	return (0);
}

int	render_points(int **matrix, t_r_c dims)
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, SC_WIDTH, SC_HEIGHT, "Iso View");
	data.img = mlx_new_image(data.mlx, SC_WIDTH, SC_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
			&data.line_length, &data.endian);
	draw_all_pts_n_lns(dims, matrix, data, iso_proj);
	free_matrix(matrix, dims.rows);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.mlx_win, 17, 0L, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
