/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:38:22 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/07 17:38:23 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_r_c	num_rows_and_cols(char *map)
{
	int		fd;
	int		i_row;
	int		i_col;
	char	*line;
	char	**result;
	t_r_c	rows_and_cols;

	rows_and_cols.rows = 0;
	rows_and_cols.cols = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (rows_and_cols);
	i_row = 0;
	line = get_next_line(fd);
	while (line)
	{
		result = ft_split(line, ' ');
		if (i_row == 0)
		{
			i_col = 0;
			while (result[i_col])
				i_col++;
			rows_and_cols.cols = i_col;
		}
		i_row++;
		free(result);
		line = get_next_line(fd);
	}
	free(line);
	rows_and_cols.rows = i_row;
	close(fd);
	return (rows_and_cols);
}

int	**create_matrix(int rows, int cols)
{
	int	**matrix;
	int	i;

	matrix = (int **)malloc(rows * sizeof(int *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = (int *)malloc(cols * sizeof(int));
		if (!matrix[i])
		{
			while (--i >= 0)
				free(matrix[i]);
			free(matrix);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

int	**convert_map_matrix(char *map)
{
	int		fd;
	int		i_row;
	int		i_col;
	int		**map_3d;
	char	*line;
	char	**result;
	t_r_c	dims;

	dims = num_rows_and_cols(map);
	if (dims.rows == 0 || dims.cols == 0)
		return (NULL);
	map_3d = create_matrix(dims.rows, dims.cols);
	if (!map_3d)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i_row = 0;
	line = get_next_line(fd);
	while (line)
	{
		result = ft_split(line, ' ');
		i_col = 0;
		while (result[i_col])
		{
			map_3d[i_row][i_col] = atoi(result[i_col]);
			i_col++;
		}
		free(result);
		line = get_next_line(fd);
		i_row++;
	}
	free(line);
	close(fd);
	return (map_3d);
}
