/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:16:51 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/11 17:39:34 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	malloc_color(t_data *data)
{
	data->floor = (t_color *)malloc(sizeof(t_color));
	data->ceilling = (t_color *)malloc(sizeof(t_color));
	data->w_north = (t_color *)malloc(sizeof(t_color));
	data->w_south = (t_color *)malloc(sizeof(t_color));
	data->w_east = (t_color *)malloc(sizeof(t_color));
	data->w_west = (t_color *)malloc(sizeof(t_color));
	if (!data->floor || !data->ceilling)
		return(ERROR);
	return(SUCCESS);
}

int malloc_img(t_data *data)
{
	data->game_img = (t_img *)malloc(sizeof(t_img));
	if (!data->game_img)
		return(ERROR);
	return(SUCCESS);
}

int	init(t_data *data)
{
	if (malloc_color(data) == ERROR)
		return(ERROR);
	if (malloc_img(data) == ERROR)
		return(ERROR);
	data->pos_x = 5;
	data->pos_y = 7;
	data->dir_x = 0;
	data->dir_y = -0.99;
	data->plane_x = -0.80;
	data->plane_y = 0;
	data->hit = 0;
	data->side = 0;
	data->screen_height = screenHeight;
	data->screen_width = screenWidth;
	data->w_north->r = 0;
	data->w_north->g = 0;
	data->w_north->b = 255;
	data->w_south->r = 255;
	data->w_south->g = 0;
	data->w_south->b = 0;
	data->w_east->r = 252;
	data->w_east->g = 255;
	data->w_east->b = 38;
	data->w_west->r = 0;
	data->w_west->g = 255;
	data->w_west->b = 0;
	data->ceilling->r = 0;
	data->ceilling->g = 0;
	data->ceilling->b = 0;
	data->floor->r = 0;
	data->floor->g = 0;
	data->floor->b = 0;
	data->speed = 0.1;
	data->wall_text = 0;
	return(SUCCESS);
}