/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:37:39 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 22:51:02 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "../libft/libft.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define SUCCESS 0
# define ERROR -1
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define EXIT 53
# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4
# define CEILING 5
# define FLOOR 6
# define RED 7
# define GREEN 8
# define BLUE 9
# define S_NORTH 6
# define S_SOUTH 7
# define S_EAST 8
# define S_WEST 9

typedef struct s_color
{
	int	r;
	int	g;
	int	b;	
}	t_color;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;		
	int			width;
	int			height;
	int			endian;
}	t_img;

typedef struct s_tex
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;		
	int			width;
	int			height;
	int			endian;
}	t_tex;

typedef struct s_data
{
	int				**map;
	void			*mlx;
	void			*win;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			wall_dist;
	double			speed;
	double			tex_pos;
	int				wall_text;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
	int				screen_height;
	int				screen_width;
	int				map_width;
	int				map_height;
	double			line_height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				rotate_left;
	int				rotate_right;
	double			step_tex;
	unsigned int	color;
	struct s_color	*floor;
	struct s_color	*ceiling;
	struct s_tex	*text_north;
	struct s_tex	*text_south;
	struct s_tex	*text_east;
	struct s_tex	*text_west;
	struct s_img	*game_img;
	char			*path_north;
	char			*path_south;
	char			*path_east;
	char			*path_west;
	char			orientation;
	char			**file_content;
}	t_data;

/* utils */
void	init(t_data *data);
int		create_map(t_data *data);
void	free_data(t_data *data);
void	ft_exit(t_data *data);
int		malloc_all(t_data *data);
void	ft_error(t_data *data, char *message);
void	ft_error_line(t_data *data, int line);
void	ft_error_map_wall(t_data *data);
void	ft_error_map_small(t_data *data);
char	*trim_space(char *str);
void	malloc_map(t_data *data);
void	map_to_int(t_data *data, int first_line, int last_line);
void	check_map(t_data *data);
void	search_player_pos(t_data *data);

/* exec */
int		minilibx_init(t_data *data);
void	exec(t_data *data);
int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		raycast(t_data *data);
int		create_rgb_struct(t_color *color);
void	draw(t_data *data, int x);
int		run(t_data *data);
void	event(t_data *data);
void	move(t_data *data);
int		ft_charge_textures(t_data *data);
void	wall_tex(t_data *data);
void	get_tex_pixl(t_data *data);
void	file_exist(t_data *data, int identifier);

/* parsing */

void	check_argument(int argc, char **argv, int *fd);
void	load_file_content(t_data *data, int fd);
void	parsing(t_data *data, int fd);
void	ft_split_cub(t_data *data, char *str);
void 	check_dup_alloc(t_data *data, int identifer);
int		is_empty_line(char *str);
void	add_color_in_data(t_data *data, char *str, int identifier);
int		parse_path_and_colors(t_data *data);
int		check_line_map(t_data *data, int i);
void 	size_of_map(t_data *data, int i, int last_line);
void	search_player_pos(t_data *data);

#endif