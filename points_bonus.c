/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:19:59 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/08 19:20:01 by luide-ca         ###   ########.fr       */
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

t_3d_pt	bonus_descale_z(t_3d_pt point, t_data data)
{
	point.z = point.z * data.z_value;
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
