#include "./mlx/mlx.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	//int     x, y, radius, center_x, center_y;
	
	mlx = mlx_init();
	// img.bits_per_pixel = 32;
	// img.line_length = 1920 * 4;
	// img.endian = 1;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// y = 535;
	// while (y <= 545)
	// {
	// 	x = 955;
	// 	while (x <= 965)
	// 	{
	// 		if ((y % 10 == 5) || (x % 10 == 5))
	// 			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	// 		x++;
	// 	}
	// 	y++;
	// }
	draw_grid(img, 10, 5);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}


