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

t_3d_pt	scale_proj(t_3d_pt point)
{
	int	scale;
	/* create a logic that scale the img in the middle of the screen*/
	scale = 10;
	point.x = point.x * scale;
	point.y = point.y * scale;
	point.z = point.z * scale;
	return (point);
}

t_2d_pt isometric_proj(t_3d_pt point)
{
	t_2d_pt	projected;

	projected.x = (int)((point.x - point.y) * cos(M_PI / 6));
	projected.y = (int)((point.x + point.y) * sin(M_PI / 6) - point.z);
	return (projected);
}

t_2d_pt	translate_proj(t_2d_pt point)
{
	int	width_factor;
	int	height_factor;
	/* create a logic that centralize the img in 
		the middle of the screen using dims*/
	width_factor = 2;
	height_factor = 3;
	point.x = point.x + SC_WIDTH / width_factor;
	point.y = point.y + SC_HEIGHT / height_factor;
	return (point);
}

t_2d_pt rotate_proj(t_2d_pt point, double angle)
{
	point.x = point.x * cos(angle) - point.y * sin(angle);
	point.y = point.x * sin(angle) + point.y * cos(angle);
	return (point);
}
