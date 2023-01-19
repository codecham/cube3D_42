/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:37:35 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 22:26:41 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	This function convert the char **map to a int **map.

	0 = empty_space
	1 = Wall
	-1 = space not in map
*/

void	add_player_pos(t_data *data, int line, int i, char *str)
{
	if (str[i] == 'N')
		data->map[line][i] = S_NORTH;
	else if (str[i] == 'S')
		data->map[line][i] = S_SOUTH;
	else if (str[i] == 'W')
		data->map[line][i] = S_WEST;
	else if (str[i] == 'E')
		data->map[line][i] = S_EAST;
}

void	copy_one_line(t_data *data, int line, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			data->map[line][i] = 0;
		else if (str[i] == '1')
			data->map[line][i] = 1;
		else
			add_player_pos(data, line, i, str);
		i++;
		if (str[i] == '\n')
			break ;
	}
}

void	map_to_int(t_data *data, int first_line, int last_line)
{
	int i;

	i = 0;
	while (first_line <= last_line)
	{
		copy_one_line(data, i, data->file_content[first_line]);
		first_line++;
		i++;
	}
}
