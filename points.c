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

t_2d_pt	projection(t_3d_pt point, t_data data)
{
	t_2d_pt	converted;

	point = rotate_proj_x(point, data);
	point = scale_proj(point, data);
	converted = isometric_proj(point);
	converted = translate_proj(converted, data);
	converted = rotate_proj_y(converted, data);
	return (converted);
}
