/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:09:35 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/23 14:52:20 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	This file contains all the parsing functions part.

	- 	First the function load_file_content, will read and stock all the
		config file .cub in char **data->file_content

	-	Second the function parse_path_and_colors will... parse and fill
		the path and the colors in our structure data. It returns the last line
		who's contain a path or a color
*/

int	jump_empty_line(t_data *data, int i)
{
	if (data->file_content[i] == 0)
		ft_error(data, "No map found in cub file");
	while (data->file_content[i] && is_empty_line(data->file_content[i]) == 1)
		i++;
	if (data->file_content[i] == 0)
		ft_error(data, "No map found in cub file");
	return (i);
}

void	parsing(t_data *data, int fd)
{
	int	i;
	int	last_line;

	load_file_content(data, fd);
	i = parse_path_and_colors(data);
	i = jump_empty_line(data, i);
	last_line = check_line_map(data, i);
	size_of_map(data, i, last_line);
	malloc_map(data);
	map_to_int(data, i, last_line);
	search_player_pos(data);
	check_map(data);
}
