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

void	free_split_n_line(t_read_map infos)
{
	ft_free_split(infos.result, infos.cols);
	free(infos.line);
}

void	free_matrix(int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

t_r_c	num_rows_and_cols(char *map)
{
	int		fd;
	char	*line;
	t_r_c	dims;

	dims.rows = 0;
	dims.cols = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (dims);
	line = get_next_line(fd);
	while (line)
	{
		dims.cols = ft_count_items(line, ' ');
		dims.rows++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (dims);
}

int	**create_matrix(char *map)
{
	int				**matrix;
	int				i;
	t_r_c			dims;

	dims = num_rows_and_cols(map);
	if (dims.rows == 0 || dims.cols == 0)
		return (NULL);
	matrix = (int **)malloc(dims.rows * sizeof(int *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < dims.rows)
	{
		matrix[i] = (int *)malloc(dims.cols * sizeof(int));
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
	int				**map_3d;
	t_read_map		infos;

	map_3d = create_matrix(map);
	infos.fd = open(map, O_RDONLY);
	if (infos.fd == -1)
		return (NULL);
	infos.rows = 0;
	infos.line = get_next_line(infos.fd);
	while (infos.line)
	{
		infos.result = ft_split(infos.line, ' ');
		infos.cols = 0;
		while (infos.result[infos.cols])
		{
			map_3d[infos.rows][infos.cols] = ft_atoi(infos.result[infos.cols]);
			infos.cols++;
		}
		free_split_n_line(infos);
		infos.line = get_next_line(infos.fd);
		infos.rows++;
	}
	free(infos.line);
	close(infos.fd);
	return (map_3d);
}
