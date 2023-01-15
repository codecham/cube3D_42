/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:32:00 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/15 17:31:44 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	draw_floor_ceilling()
{
	
}

void	draw_vert_line(t_data *data, int draw_start, int draw_end, int x)
{
	int y;
	int color;

	y = 0;
	while(y < draw_start)
	{
		my_mlx_pixel_put(data->game_img, x, y, create_rgb_struct(data->ceiling));
		y++;
	}
	while(y < draw_end)
	{
		if (data->wall_text == NORTH)
			color = create_rgb_struct(data->w_north);
		else if(data->wall_text == SOUTH)
			color = create_rgb_struct(data->w_south);
		else if(data->wall_text == WEST)
			color = create_rgb_struct(data->w_west);
		else if(data->wall_text == EAST)
			color = create_rgb_struct(data->w_east);
		my_mlx_pixel_put(data->game_img, x, y, color);
		y++;
	}
	while(y < data->screen_height)
	{
		my_mlx_pixel_put(data->game_img, x, y, create_rgb_struct(data->floor));
		y++;
	}
}

void	draw(t_data *data, int x)
{
	data->draw_start = -data->line_height / 2 + data->screen_height / 2;
	data->draw_end = data->line_height / 2 + data->screen_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_end >= data->screen_height)
		data->draw_end = data->screen_height - 1;
	draw_vert_line(data, data->draw_start, data->draw_end, x);
}