/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:24:08 by dcorenti          #+#    #+#             */
/*   Updated: 2022/12/13 14:17:44 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	This file contains functions who's init all data in structure after allocation.

	PARAMETERS: The data strcuture
*/

void	ft_init_img(t_img *img)
{
	img->mlx = NULL;
	img->img = NULL;
	img->relative_path = NULL;
	img->img_width = 0;
	img->img_height = 0;
}

void	ft_init_player(t_player *player)
{
	player->angle = 0;
	player->pos_x = 0;
	player->pos_y = 0;
	player->speed = 0;
}

void	ft_init_color(t_color *color)
{
	color->b = 0;
	color->g = 0;
	color->r = 0;
}

void	ft_init(t_data *data)
{
	data->mlx = 0;
	data->win_mlx = 0;
	data->map = 0;
	data->north_path = 0;
	data->south_path = 0;
	data->east_path = 0;
	data->west_path = 0;
	ft_init_img(data->north_texture);
	ft_init_img(data->south_texture);
	ft_init_img(data->east_texture);
	ft_init_img(data->west_texture);
	ft_init_player(data->player);
	ft_init_color(data->ceilling_color);
	ft_init_color(data->floor_color);
}
