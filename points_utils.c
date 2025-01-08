/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:52:40 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/07 18:52:41 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3d_pt	rotate_proj_x(t_3d_pt point, t_data data)
{
	double	temp_y;
	double	temp_z;

	temp_y = point.y * cos(data.angle_x) - point.z * sin(data.angle_x);
	temp_z = point.y * sin(data.angle_x) + point.z * cos(data.angle_x);
	point.y = temp_y;
	point.z = temp_z;
	return (point);
}

t_3d_pt	scale_proj(t_3d_pt point, t_data data)
{
	point.x = point.x * data.scale;
	point.y = point.y * data.scale;
	point.z = point.z * data.scale;
	return (point);
}

t_2d_pt	isometric_proj(t_3d_pt point)
{
	t_2d_pt	projected;

	projected.x = (int)((point.x - point.y) * cos(M_PI / 6));
	projected.y = (int)((point.x + point.y) * sin(M_PI / 6) - point.z);
	return (projected);
}

t_2d_pt	translate_proj(t_2d_pt point, t_data data)
{
	point.x = point.x + SC_WIDTH / data.width_factor;
	point.y = point.y + SC_HEIGHT / data.height_factor;
	return (point);
}

t_2d_pt	rotate_proj_y(t_2d_pt point, t_data data)
{
	int	dx;
	int	dy;

	dx = point.x - SC_WIDTH / data.width_factor;
	dy = point.y - SC_HEIGHT / 3;
	point.x = dx * cos(data.angle_y) - dy * \
		sin(data.angle_y) + SC_WIDTH / data.width_factor;
	point.y = dx * sin(data.angle_y) + dy * cos(data.angle_y) + SC_HEIGHT / 3;
	return (point);
}
