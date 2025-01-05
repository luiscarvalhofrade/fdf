#include "fdf.h"

int flag_switcher(int num_cl, int num_ln, int flags)
{
    if (num_cl % 2 != 0)
        flags = flags & ~NUM_CL_EVEN;
    if (num_ln % 2 != 0)
        flags = flags & ~NUM_LN_EVEN;
    return (flags);
}

void   draw_grid_2(t_data img, int number_columns, int number_lines)
{
    int flags;

    flags = NUM_CL_EVEN | NUM_CL_EVEN;
    flags = flag_switcher(number_columns, number_lines, flags);
}

void	draw_grid(t_data img, int number_columns, int number_lines)
{
	int x, y;
	int x_max, y_max;

	if (number_columns % 2 == 0)
		x_max = 960 + 10 * (number_columns/2);
	else
		x_max = 960 + 5 + 10 * (number_columns/2);
	if (number_lines % 2 == 0)
	{
		y = 540 - 10 * (number_lines/2);
		y_max = 540 + 10 * (number_lines/2);
	}
	else
	{
		y = 540 - 5 - 10 * (number_lines/2);
		y_max = 540 + 5 + 10 * (number_lines/2);
	}	
	while (y <= y_max)
	{	
		if (number_columns % 2 == 0)
			x = 960 - 10 * (number_columns/2);
		else
			x = 960 - 5 - 10 * (number_columns/2);
		while (x <= x_max)
		{
			if ((y % 10 == 5) || (x % 10 == 5))
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
}