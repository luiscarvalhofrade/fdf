/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:02:23 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/07 13:02:24 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d_pt	iso_proj(t_3d_pt point)
{
	t_2d_pt	projected;

	point.x = point.x * 10;
	point.y = point.y * 10;
	point.z = point.z * 10;
	projected.x = (int)((point.x - point.y) * cos(M_PI / 6));
	projected.y = (int)((point.x + point.y) * sin(M_PI / 6) - point.z);
	projected.x = projected.x + SC_WIDTH / 2;
	projected.y = projected.y + SC_HEIGHT / 3;
	return (projected);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SC_WIDTH || y < 0 || y >= SC_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham_line(t_data *img, t_2d_pt start, t_2d_pt end, int color)
{
	t_bre_eq	bre_eq;

	bre_eq.dx = abs(end.x - start.x);
	bre_eq.dy = abs(end.y - start.y);
	if (start.x < end.x)
		bre_eq.sx = 1;
	else
		bre_eq.sx = -1;
	if (start.y < end.y)
		bre_eq.sy = 1;
	else
		bre_eq.sy = -1;
	bre_eq.err = bre_eq.dx - bre_eq.dy;
	while (1)
	{
		my_mlx_pixel_put(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		bre_eq.e2 = 2 * bre_eq.err;
		if (bre_eq.e2 > -bre_eq.dy)
		{
			bre_eq.err -= bre_eq.dy;
			start.x += bre_eq.sx;
		}
		if (bre_eq.e2 < bre_eq.dx)
		{
			bre_eq.err += bre_eq.dx;
			start.y += bre_eq.sy;
		}
	}
}
