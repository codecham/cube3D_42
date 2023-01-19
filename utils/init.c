/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:16:51 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 00:47:31 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	Simplement une fonction qui initialse notre structure
*/

void	init(t_data *data)
{
	data->floor = NULL;
	data->ceiling = NULL;
	data->text_north = NULL;
	data->text_south = NULL;
	data->text_east = NULL;
	data->text_west = NULL;
	data->game_img = NULL;
	data->path_north = NULL;
	data->path_south = NULL;
	data->path_east = NULL;
	data->path_west = NULL;
	data->pos_x = -1;
	data->pos_y = -1;
	data->speed = 0.1;
	data->wall_text = 0;
	data->move_up = 0;
	data->move_down = 0;
	data->move_left = 0;
	data->move_right = 0;
	data->rotate_left = 0;
	data->rotate_right = 0;
	data->file_content = NULL;
}
