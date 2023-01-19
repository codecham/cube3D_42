/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:44:35 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 20:06:52 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	This function check all character in the map and if the map don't contains
	empty line and if is the last in file

		1) Check all the character in a line

		2) If we have a empty line, check if all next line are empty or not

		3) return the last line of the map
*/

int	char_is_valid_map(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	if (c == '0' || c == '1')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

void	string_is_valid(t_data *data, char *str, int line)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (char_is_valid_map(str[i]) == 0)
		{
			printf("Error\n");
			printf("line %d: Found bad character in map: %c\n", \
			line + 1, str[i]);
			ft_exit(data);
		}
		i++;
	}
}

void	check_empty_line_eof(t_data *data, int line)
{
	int	tmp;

	tmp = line;
	if (data->file_content[line] == 0)
		return ;
	while (data->file_content[line] && \
		is_empty_line(data->file_content[line]) == 1)
		line++;
	if (data->file_content[line] != 0)
	{
		string_is_valid(data, data->file_content[line], line);
		printf("Error\n");
		printf("Line %d: Map can't contains empty line\n", tmp);
		ft_exit(data);
	}
}

int	check_line_map(t_data *data, int i)
{
	while (data->file_content[i])
	{
		string_is_valid(data, data->file_content[i], i);
		if (is_empty_line(data->file_content[i]) == 1)
			check_empty_line_eof(data, i + 1);
		i++;
	}
	i--;
	while (is_empty_line(data->file_content[i]) == 1)
		i--;
	return (i);
}
