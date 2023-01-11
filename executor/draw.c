/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:32:00 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/11 19:40:23 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	draw_vert_line(t_data *data, int draw_start, int draw_end, int x)
{
	int y;
	int color;

	y = 0;
	while(y < draw_start)
	{
		my_mlx_pixel_put(data->game_img, x, y, create_rgb_struct(data->ceilling));
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
	int draw_start;
	int draw_end;
	// int y;
	
	// y = 0;
	// printf("line_height = %d\n", data->line_height);
	draw_start = -data->line_height / 2 + data->screen_height / 2;
	draw_end = data->line_height / 2 + data->screen_height / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= data->screen_height)
		draw_end = data->screen_height - 1;
	draw_vert_line(data, draw_start, draw_end, x);
	// printf("draw start = %d | draw_end = %d\n", draw_start, draw_end);
}