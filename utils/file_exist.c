/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 05:22:36 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 05:44:35 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	id_first_c(char *str)
{
	int i;

	i = 2;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

void	error_file_exist(t_data *data, int identifier)
{
	printf("Error\n");
	if (identifier == NORTH)
		printf("File [%s] doesn't exist or is a directory\n", &data->path_north[id_first_c(data->path_north)]);
	if (identifier == SOUTH)
		printf("File [%s] doesn't exist or is a directory\n", &data->path_south[id_first_c(data->path_south)]);
	if (identifier == EAST)
		printf("File [%s] doesn't exist or is a directory\n", &data->path_east[id_first_c(data->path_east)]);
	if (identifier == WEST)
		printf("File [%s] doesn't exist or is a directory\n", &data->path_west[id_first_c(data->path_west)]);
	ft_exit(data);
}

void	file_exist(t_data *data, int identifier)
{
	int fd;

	if (identifier == NORTH)
		fd = open(data->path_north, O_RDONLY);
	if (identifier == SOUTH)
		fd = open(data->path_south, O_RDONLY);
	if (identifier == EAST)
		fd = open(data->path_east, O_RDONLY);
	if (identifier == WEST)
		fd = open(data->path_west, O_RDONLY);
	if (fd == -1)
		error_file_exist(data, identifier);
	close(fd);
}
