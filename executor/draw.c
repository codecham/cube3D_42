/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:32:00 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/17 04:51:53 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int		get_height_tex(t_data *data)
{
	if (data->wall_text == NORTH)
		return(data->text_north->height);
	else if (data->wall_text == SOUTH)
		return(data->text_south->height);
	else if (data->wall_text == EAST)
		return(data->text_east->height);
	else
		return(data->text_west->height);
}

void	draw(t_data *data, int x)
{
	int y;
	int height;

	y = 0;
	height = get_height_tex(data);
	while(y < data->draw_start)
	{
		my_mlx_pixel_put(data->game_img, x, y, create_rgb_struct(data->ceiling));
		y++;
	}
	while(y <= data->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (height - 1);
		data->tex_pos += data->step_tex;
		get_tex_pixl(data);
		my_mlx_pixel_put(data->game_img, x, y, data->color);
		y++;
	}
	while(y < data->screen_height)
	{
		my_mlx_pixel_put(data->game_img, x, y, create_rgb_struct(data->floor));
		y++;
	}
}
