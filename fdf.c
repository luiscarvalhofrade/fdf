#include "fdf.h"

int	render_points(int **matrix, int rows, int cols)
{
	int		i_row;
	int		y;
	int		x;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_3d_pt	point3d_start;
	t_3d_pt	point3d_end;
	t_2d_pt	start;
	t_2d_pt	end;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Isometric View");
	img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			point3d_start.x = x;
			point3d_start.y = y;
			point3d_start.z = matrix[y][x];
			if (x + 1 < cols)
			{
				point3d_end.x = x + 1;
				point3d_end.y = y;
				point3d_end.z = matrix[y][x + 1];
				start = isometric_projection(point3d_start);
				end = isometric_projection(point3d_end);
				bresenham_line(&img, start, end, 0x00FF0000);
			}
			if (y + 1 < rows)
			{
				point3d_end.x = x;
				point3d_end.y = y + 1;
				point3d_end.z = matrix[y + 1][x];
				start = isometric_projection(point3d_start);
				end = isometric_projection(point3d_end);
				bresenham_line(&img, start, end, 0x00FF0000);
			}
			x++;
		}
		y++;
	}
	i_row = 0;
	while (i_row < rows)
	{
		free(matrix[i_row]);
		i_row++;
	}
	free(matrix);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

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
	render_points(matrix, dims.rows, dims.cols);
	return (0);
}
