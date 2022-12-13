/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:37:39 by dcorenti          #+#    #+#             */
/*   Updated: 2022/12/13 14:25:11 by dcorenti         ###   ########.fr       */
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

typedef struct	s_color
{
	int r;
	int g;
	int b;	
}	t_color;

typedef struct	s_img
{
	void	*mlx;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_player
{
	int	pos_x;
	int pos_y;
	int speed;
	int angle;
}	t_player;


typedef struct	s_data
{
	void			*mlx;
	void			*win_mlx;
	int				win_size_x;
	int				win_size_y;
	char			**map;
	char			*north_path;
	char			*south_path;
	char			*east_path;
	char			*west_path;
	struct s_img	*north_texture;
	struct s_img	*south_texture;
	struct s_img	*east_texture;
	struct s_img	*west_texture;
	struct s_player	*player;
	struct s_color	*floor_color;
	struct s_color	*ceilling_color;
}	t_data;


// utils
t_data 	*ft_malloc_data(void);
void	ft_init(t_data *data);
int		ft_error_free(t_data *data, char *message);
int		ft_error(char *message);
void	ft_free_data(t_data *data);

#endif