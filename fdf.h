/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:01:46 by luide-ca          #+#    #+#             */
/*   Updated: 2025/01/07 13:01:48 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# ifndef SC_WIDTH
#  define SC_WIDTH 1024
# endif
# ifndef SC_HEIGHT
#  define SC_HEIGHT 768
# endif

// # ifndef ESC_KEY
// #  define ESC_KEY 53
// # endif
// # ifndef RIGHT_KEY
// #  define RIGHT_KEY 124
// # endif
// # ifndef LEFT_KEY
// #  define LEFT_KEY 123
// # endif
// # ifndef UP_KEY
// #  define UP_KEY 126
// # endif
// # ifndef DOWN_KEY
// #  define DOWN_KEY 125
// # endif
# ifndef ESC_KEY
#  define ESC_KEY 65307
# endif
# ifndef RIGHT_KEY
#  define RIGHT_KEY 65363
# endif
# ifndef LEFT_KEY
#  define LEFT_KEY 65361
# endif
# ifndef UP_KEY
#  define UP_KEY 65362
# endif
# ifndef DOWN_KEY
#  define DOWN_KEY 65364
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"

typedef struct s_read_map
{
	int		rows;
	int		cols;
	int		fd;
	char	*line;
	char	**result;
}			t_read_map;

typedef struct s_r_c
{
	int	rows;
	int	cols;
}		t_r_c;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	angle_x;
	double	angle_y;
	int		**matrix;
	t_r_c	dims;
}				t_data;

typedef struct s_3d_pt
{
	int	x;
	int	y;
	int	z;
}	t_3d_pt;

typedef struct s_2d_pt
{
	int	x;
	int	y;
}	t_2d_pt;

typedef struct s_st_en_pts
{
	t_3d_pt	point3d_start;
	t_3d_pt	point3d_end;
}			t_st_en_pts;

typedef struct s_list
{
	char			*content;
	struct s_list	*next_node;
}					t_list;

typedef struct s_bre_eq
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bre_eq;

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);

int		ft_found_new_line(t_list *list);
int		ft_len_of_new_line(t_list *list);
int		render_points(int **matrix, t_r_c dims);
int		ft_count_items(const char *s, char c);
int		**create_matrix(char *map);
int		**convert_map_matrix(char *map);

void	ft_copy_string(t_list *list, char *str);
void	ft_free(t_list **list, t_list *clean_node, char *buffer);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	line_algo(t_data *img, t_2d_pt start, t_2d_pt end, int color);
void	draw_pt_n_ln(t_3d_pt pt3d_start, t_3d_pt pt3d_end, t_data data);
void	draw_all_pts_n_lns(t_data data);
void	free_matrix(int **matrix, int size);

t_list	*ft_find_last_node(t_list *list);

t_3d_pt	rotate_proj_x(t_3d_pt point, double angle);
t_3d_pt	scale_proj(t_3d_pt point);

t_2d_pt	isometric_proj(t_3d_pt point);
t_2d_pt	translate_proj(t_2d_pt point);
t_2d_pt	rotate_proj_y(t_2d_pt point, double angle);
t_2d_pt	projection(t_3d_pt point, double angle_y, double angle_x);

t_r_c	num_rows_and_cols(char *map);

#endif