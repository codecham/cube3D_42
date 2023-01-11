/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:29:33 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/11 19:39:20 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	rotate(t_data *data, int advance)
{
	double dir;
	double plane;

	dir = data->dir_x;
	plane = data->plane_x;
	data->dir_x = data->dir_x * cos(advance * data->speed) - data->dir_y* sin(advance * data->speed);
	data->dir_y = dir * sin(advance * data->speed) + data->dir_y * cos(advance * data->speed);
	data->plane_x = data->plane_x * cos(advance * data->speed) - data->plane_y * sin(advance * data->speed);
	data->plane_y = plane * sin(advance * data->speed) + data->plane_y * cos(advance * data->speed);
}

void	move_left_right(t_data *data, int key_code)
{
	if (key_code == KEY_LEFT)
	{
		if (data->map[(int)(data->pos_y - data->dir_x * data->speed)][(int)(data->pos_x)] != 1)
			data->pos_y += -data->dir_x * data->speed;
		if (data->map[(int)data->pos_y][(int)(data->pos_x + data->dir_y * data->speed)] != 1)
			data->pos_x += data->dir_y * data->speed;
	}
	else if (key_code == KEY_RIGHT)
	{
		if (data->map[(int)(data->pos_y + data->dir_x * data->speed)][(int)(data->pos_x)] != 1)
			data->pos_y -= -data->dir_x * data->speed;
		if (data->map[(int)data->pos_y][(int)(data->pos_x - data->dir_y * data->speed)] != 1)
			data->pos_x -= data->dir_y * data->speed;
	}
}

void	move_down_up(t_data *data, int key_code)
{
	if (key_code == KEY_UP)
	{
		if (data->map[(int)(data->pos_y)][(int)(data->pos_x + data->dir_x * data->speed)] != 1)
			data->pos_x += data->dir_x * data->speed;
		if (data->map[(int)(data->pos_y + data->dir_y * data->speed)][(int)(data->pos_x)] != 1)
			data->pos_y += data->dir_y * data->speed;
	}
	else if (key_code == KEY_DOWN)
	{
		if (data->map[(int)(data->pos_y)][(int)(data->pos_x - data->dir_x * data->speed)] != 1)
			data->pos_x -= data->dir_x * data->speed;
		if (data->map[(int)(data->pos_y - data->dir_y * data->speed)][(int)(data->pos_x)] != 1)
			data->pos_y -= data->dir_y * data->speed;
	}
}

void	move(t_data *data, int key_code)
{
	if (key_code == KEY_UP || key_code == KEY_DOWN)
		move_down_up(data, key_code);
	else if (key_code == KEY_LEFT || key_code == KEY_RIGHT)
		move_left_right(data, key_code);
	else if (key_code == ROTATE_LEFT)
		rotate(data, -1);
	else if (key_code == ROTATE_RIGHT)
		rotate(data, 1);
}