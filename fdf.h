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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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

typedef struct s_r_c
{
	int	rows;
	int	cols;
}		t_r_c;

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
char	**ft_split(char const *s, char c);

int		ft_found_new_line(t_list *list);
int		ft_len_of_new_line(t_list *list);
int		**convert_map_matrix(char *map);
int		render_points(int **matrix, int rows, int cols);

void	ft_copy_string(t_list *list, char *str);
void	ft_free(t_list **list, t_list *clean_node, char *buffer);
void	bresenham_line(t_data *img, t_2d_pt start, t_2d_pt end, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

t_list	*ft_find_last_node(t_list *list);

t_2d_pt	iso_proj(t_3d_pt point);

t_r_c	num_rows_and_cols(char *map);

#endif