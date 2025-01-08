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
