/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:32:55 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/22 16:48:58 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	get_wall_text(t_data *data)
{
	if (data->side == 0)
	{
		if (data->step_x > 0 && data->map_x > (int)data->pos_x)
			data->wall_text = EAST;
		else
			data->wall_text = WEST;
	}
	else
	{
		if (data->step_y > 0 && data->map_y > (int)data->pos_y)
			data->wall_text = SOUTH;
		else
			data->wall_text = NORTH;
	}
}

void	dda_algorithm(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map[data->map_y][data->map_x] == 1)
			data->hit = 1;
	}
	get_wall_text(data);
	data->hit = 0;
}

void	set_step(t_data *data)
{
	if (data->ray_dir_x > 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x)
			* data->delta_dist_x;
	}
	if (data->ray_dir_y > 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y)
			* data->delta_dist_y;
	}
}

void	size_ray(t_data *data)
{
	if (data->side == 0)
		data->wall_dist = fabs((data->map_x - data->pos_x
					+ (1 - data->step_x) / 2) / data->ray_dir_x);
	else
		data->wall_dist = fabs((data->map_y - data->pos_y
					+ (1 - data->step_y) / 2) / data->ray_dir_y);
	data->line_height = fabs((data->screen_height / data->wall_dist));
	data->draw_start = (-1 * (data->line_height)) / 2 + data->screen_height / 2;
	data->draw_end = data->line_height / 2 + data->screen_height / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_end >= data->screen_height)
		data->draw_end = data->screen_height - 1;
}

int	raycast(t_data *data)
{
	int	x;

	x = 0;
	while (x < data->screen_width)
	{
		data->camera_x = 2 * x / (double)data->screen_width - 1;
		data->ray_dir_x = -data->dir_x + data->plane_x * data->camera_x;
		data->ray_dir_y = -data->dir_y + data->plane_y * data->camera_x;
		data->delta_dist_x = sqrt(1 + ((powf(data->ray_dir_y, 2)
						/ powf(data->ray_dir_x, 2))));
		data->delta_dist_y = sqrt(1 + ((powf(data->ray_dir_x, 2)
						/ powf(data->ray_dir_y, 2))));
		data->map_x = (int)data->pos_x;
		data->map_y = (int)data->pos_y;
		set_step(data);
		dda_algorithm(data);
		size_ray(data);
		wall_tex(data);
		draw(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->game_img->img, 0, 0);
	return (SUCCESS);
}
