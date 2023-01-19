/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:52:17 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 22:35:06 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	This function check if the map is closed by walls or not

	1) if we have a 0 in border it's not close

	2) If we not on border we check all case around for see it it's -1 (void)

*/

int	is_border(t_data *data, int x, int y)
{
	if (x == 0 || x == data->map_width - 1)
		return (1);
	if (y == 0 || y == data->map_height -1)
		return (1);
	return (0);
}

int	check_around(t_data *data, int x, int y)
{
	if (data->map[y][x - 1] == -1)
		return (1);
	if (data->map[y][x + 1] == -1)
		return (1);
	if (data->map[y - 1][x] == -1)
		return (1);
	if (data->map[y + 1][x] == -1)
		return (1);
	return (0);
}

void	check_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		while (x < data->map_width)
		{
			if (data->map[y][x] == 0)
			{
				if (is_border(data, x, y) == 1)
					ft_error_map_wall(data);
				if (check_around(data, x, y) == 1)
					ft_error_map_wall(data);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
