/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:18:08 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/07 19:18:09 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SC_WIDTH || y < 0 || y >= SC_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	handle_esc_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		if (data->img)
			mlx_destroy_image(data->mlx, data->img);
		if (data->mlx_win)
			mlx_destroy_window(data->mlx, data->mlx_win);
		if (data->matrix)
			free_matrix(data->matrix, data->dims.rows);
		if (data->mlx)
			mlx_destroy_display(data->mlx);
	}
	return (0);
}

int	handle_close(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->matrix)
		free_matrix(data->matrix, data->dims.rows);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
	}
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		handle_esc_keypress(keycode, data);
		exit(0);
		return (0);
	}
	else if (keycode == RIGHT_KEY || keycode == LEFT_KEY)
		hanle_rotation(keycode, data);
	else if (keycode == UP_KEY || keycode == DOWN_KEY)
		hanle_rotation(keycode, data);
	else if (keycode == F1_KEY || keycode == F2_KEY)
		handle_scale(keycode, data);
	else if (keycode == F3_KEY || keycode == F4_KEY)
		handle_translate_width(keycode, data);
	else if (keycode == F5_KEY || keycode == F6_KEY)
		handle_translate_height(keycode, data);
	else if (keycode == F7_KEY || keycode == F8_KEY)
		handle_descale_z(keycode, data);
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
	data.angle_x = 0.0;
	data.angle_y = 0.0;
	data.scale = 10;
	data.width_factor = 2;
	data.height_factor = 3.0;
	data.z_value = 1.0;
	data.matrix = matrix;
	data.dims = dims;
	draw_all_pts_n_lns(data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.mlx_win, 17, 0L, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
