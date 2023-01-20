/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path_and_colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:09:29 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/20 15:51:37 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	This function will parse the paths and the colors of our file.

	How it's works:

		- 	1) We jump all empty line

		- 	2) We delete the space before and after our line

		- 	3) We search what's the identifer and return a different postive value
			for each one.

		-  	4)
				If the identifier is 0 it means that it's not a good line.

				else If the identifier is equal to CEILLING or FLOOR we send to
				add_colors_in_data

				else the idientifer is for a path so we sent to add_path_in_data

		-	5) We check if the identifier is not already filled for double

		-	6) We loop until all the values are filled

	----------------------------------------------------------------------

	For the add_path_function:

		- 	1) We jump all the space between identifer and path

		- 	2) We dup the path in the correct variable in the data struct

		-	3) We check if the malloc in ft_strdup it's ok

		-	4) We check if the file exist


*/

int	config_is_full(t_data *data)
{
	if (data->path_north == NULL)
		return (0);
	if (data->path_south == NULL)
		return (0);
	if (data->path_east == NULL)
		return (0);
	if (data->path_west == NULL)
		return (0);
	if (data->ceiling->r == -1)
		return (0);
	if (data->floor->r == -1)
		return (0);
	return (1);
}

int	is_identifier(char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (NORTH);
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (SOUTH);
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (WEST);
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (EAST);
	if (line[0] == 'F' && line[1] == ' ')
		return (FLOOR);
	if (line[0] == 'C' && line[1] == ' ')
		return (CEILING);
	return (0);
}

void	check_double_identifier(t_data *data, int identifier)
{
	if (identifier == NORTH && data->path_north != NULL)
		ft_error(data, "Duplicated NO identifier");
	if (identifier == SOUTH && data->path_south != NULL)
		ft_error(data, "Duplicated SO identifier");
	if (identifier == EAST && data->path_east != NULL)
		ft_error(data, "Duplicated EA identifier");
	if (identifier == WEST && data->path_west != NULL)
		ft_error(data, "Duplicated WE identifier");
	if (identifier == CEILING && data->ceiling->r != -1)
		ft_error(data, "Duplicated C identifier");
	if (identifier == FLOOR && data->floor->r != -1)
		ft_error(data, "Duplicated F identifier");
}

void	add_path_file_in_data(t_data *data, char *str, int identifier)
{
	int	i;

	i = 3;
	while (str[i] && str[i] == ' ')
		i++;
	if (identifier == NORTH)
		data->path_north = ft_strdup(&str[i]);
	if (identifier == SOUTH)
		data->path_south = ft_strdup(&str[i]);
	if (identifier == EAST)
		data->path_east = ft_strdup(&str[i]);
	if (identifier == WEST)
		data->path_west = ft_strdup(&str[i]);
	check_dup_alloc(data, identifier);
	check_extension_xmp(data, &str[i]);
	file_exist(data, identifier);
}

int	parse_path_and_colors(t_data *data)
{
	int	i;
	int	identifier;

	i = 0;
	while (data->file_content[i] && config_is_full(data) == 0)
	{
		if (is_empty_line(data->file_content[i]) == 0)
		{
			data->file_content[i] = trim_space(data->file_content[i]);
			identifier = is_identifier(data->file_content[i]);
			if (identifier == 0)
				ft_error_line(data, i + 1);
			check_double_identifier(data, identifier);
			if (identifier == FLOOR || identifier == CEILING)
				add_color_in_data(data, data->file_content[i], identifier);
			else
				add_path_file_in_data(data, data->file_content[i], identifier);
		}
		i++;
	}
	if (config_is_full(data) == 0)
		ft_error(data, "cub file is incomplete");
	return (i);
}
