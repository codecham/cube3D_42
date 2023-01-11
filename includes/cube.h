/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:37:39 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/11 16:37:22 by dcorenti         ###   ########.fr       */
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

#define screenWidth 1920
#define screenHeight 1080
#define mapWidth 24
#define mapHeight 24
#define SUCCESS 0
#define ERROR -1
#define KEY_UP 13
#define KEY_DOWN 1
#define KEY_LEFT 0
#define KEY_RIGHT 2
#define ROTATE_LEFT 123
#define ROTATE_RIGHT 124
#define EXIT 53
#define NORTH 1
#define SOUTH 2
#define WEST 3
#define EAST 4


// int worldMap[mapWidth][mapHeight]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

typedef struct	s_color
{
	int r;
	int g;
	int b;	
}	t_color;

typedef struct	s_xpm_img
{
	void	*mlx;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}	t_xpm_img;

typedef struct		s_img
{
	void		*img;
	char		*addr;				// In my code I changed this to int *, which I will explain in a second
	int			bits_per_pixel;		//when using ARGB this value is always 32
	int			line_length;		//This value represents (your image width) * 4 which I will also explain after
	int			endian;				//This value can be either 0 or 1 and will indicate how the ARGB bytes are organized (from front to back or back to front)
}	t_img;

typedef struct	s_data
{
	int				**map;
	void			*mlx;
	void			*win;
	double			pos_x; //rposx
	double			pos_y; //rposy
	double			dir_x; //rdirx
	double			dir_y;	//rdiry
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
	int				line_height;
	struct	s_color *floor;
	struct	s_color *ceilling;
	struct	s_color *w_north;
	struct	s_color *w_south;
	struct	s_color *w_east;
	struct	s_color *w_west;
	struct	s_img	*game_img;
	
}	t_data;

int		init(t_data *data);
int		minilibx_init(t_data *data);
void	exec(t_data *data);
int		create_trgb(int t, int r, int g, int b);
void 	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		create_map(t_data *data);
int		raycast(t_data *data);
int 	create_rgb_struct(t_color *color);
void	draw(t_data *data, int x);
int		run(t_data *data);
void	event(t_data *data);
void	move(t_data *data, int key_code);

#endif