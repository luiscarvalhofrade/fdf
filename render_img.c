/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:38:01 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/07 17:38:03 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pt_n_ln(t_3d_pt pt3d_start, t_3d_pt pt3d_end, t_data data)
{
	t_2d_pt	start;
	t_2d_pt	end;

	start = projection(pt3d_start, data);
	end = projection(pt3d_end, data);
	line_algo(&data, start, end, 0x00FF0000);
}

t_3d_pt	define_start_pt(int x, int y, t_data data)
{
	t_3d_pt	point3d_start;

	point3d_start.x = x;
	point3d_start.y = y;
	point3d_start.z = data.matrix[y][x];
	return (point3d_start);
}

t_3d_pt	define_end_pt_x(int x, int y, t_data data)
{
	t_3d_pt	point3d_end;

	point3d_end.x = x + 1;
	point3d_end.y = y;
	point3d_end.z = data.matrix[y][x + 1];
	return (point3d_end);
}

t_3d_pt	define_end_pt_y(int x, int y, t_data data)
{
	t_3d_pt	point3d_end;

	point3d_end.x = x;
	point3d_end.y = y + 1;
	point3d_end.z = data.matrix[y + 1][x];
	return (point3d_end);
}

void	draw_all_pts_n_lns(t_data data)
{
	int			y;
	int			x;
	t_st_en_pts	pts;

	y = 0;
	while (y < data.dims.rows)
	{
		x = 0;
		while (x < data.dims.cols)
		{
			pts.point3d_start = define_start_pt(x, y, data);
			if (x + 1 < data.dims.cols)
			{
				pts.point3d_end = define_end_pt_x(x, y, data);
				draw_pt_n_ln(pts.point3d_start, pts.point3d_end, data);
			}
			if (y + 1 < data.dims.rows)
			{
				pts.point3d_end = define_end_pt_y(x, y, data);
				draw_pt_n_ln(pts.point3d_start, pts.point3d_end, data);
			}
			x++;
		}
		y++;
	}
}
