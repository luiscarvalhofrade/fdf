/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:01:46 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/07 13:01:48 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		**matrix;
	int		rows;
	int		cols;
	t_r_c	dims;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	matrix = convert_map_matrix(argv[1]);
	if (!matrix)
	{
		fprintf(stderr, "Error: Failed to convert map to matrix.\n");
		return (1);
	}
	dims = num_rows_and_cols(argv[1]);
	rows = dims.rows;
	cols = dims.cols;
	printf("Matrix dimensions: %d rows x %d columns\n", rows, cols);
	render_points(matrix, dims);
	return (0);
}
