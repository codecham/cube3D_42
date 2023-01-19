/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:09:35 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 05:58:38 by dcorenti         ###   ########.fr       */
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

void	parsing(t_data *data, int fd)
{
	int i;

	load_file_content(data, fd);
	i = parse_path_and_colors(data);
	(void)i;
}
