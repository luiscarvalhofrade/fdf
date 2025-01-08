/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:38:09 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/07 17:38:11 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d_pt	projection(t_3d_pt point, double angle_y, double angle_x)
{
	t_2d_pt	converted;

	point = rotate_proj_x(point, angle_x);
	point = scale_proj(point);
	converted = isometric_proj(point);
	converted = translate_proj(converted);
	converted = rotate_proj_y(converted, angle_y);
	return (converted);
}
