/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_control_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:38:14 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/08 15:38:16 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			free(data->mlx);
	}
	return (0);
}

int	handle_scale(int keycode, t_data *data)
{
	if (keycode == F1_KEY)
		data->scale += 1;
	else if (keycode == F2_KEY)
		data->scale -= 1;
	data->img = mlx_new_image(data->mlx, SC_WIDTH, SC_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	draw_all_pts_n_lns(*data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	handle_translate_width(int keycode, t_data *data)
{
	if (keycode == F3_KEY)
		data->width_factor += 0.2;
	else if (keycode == F4_KEY)
		data->width_factor -= 0.2;
	data->img = mlx_new_image(data->mlx, SC_WIDTH, SC_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	draw_all_pts_n_lns(*data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	handle_translate_height(int keycode, t_data *data)
{
	if (keycode == F5_KEY)
		data->height_factor += 0.2;
	else if (keycode == F6_KEY)
		data->height_factor -= 0.2;
	data->img = mlx_new_image(data->mlx, SC_WIDTH, SC_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	draw_all_pts_n_lns(*data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	hanle_rotation(int keycode, t_data *data)
{
	if (keycode == RIGHT_KEY)
		data->angle_y -= 0.1;
	else if (keycode == LEFT_KEY)
		data->angle_y += 0.1;
	else if (keycode == UP_KEY)
		data->angle_x += 0.1;
	else if (keycode == DOWN_KEY)
		data->angle_x -= 0.1;
	data->img = mlx_new_image(data->mlx, SC_WIDTH, SC_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	draw_all_pts_n_lns(*data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}
