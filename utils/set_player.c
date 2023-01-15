/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:31:33 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/12 19:33:26 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	set_orientation(t_data *data, char orientation)
{
	if (orientation == 'N')
	{
		data->dir_y = -0.99;
		data->plane_x = -0.80;
	}
	if (orientation == 'S')
	{
		data->dir_y = 0.99;
		data->plane_x = 0.80;
	}
	if (orientation == 'E')
	{
		data->dir_x = 0.99;
		data->plane_y = -0.80;
	}
	if (orientation == 'W')
	{
		data->dir_x = -0.99;
		data->plane_y = 0.80;
	}	
}

void	set_player_pos(t_data *data, int x, int y)
{
	data->pos_x = x;
	data->pos_y = y;
}
