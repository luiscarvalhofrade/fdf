#ifndef FDF_H
# define FDF_H

# define NUM_CL_EVEN 0b01
# define NUM_LN_EVEN 0b10

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	draw_grid(t_data img, int number_columns, int number_lines);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif