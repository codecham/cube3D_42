/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:51:59 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 03:00:53 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	ft_count_line_file(t_data *data, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	count++;
	if (count < 8)
		ft_error(data, "configuration file is incomplete");
	return (count);
}

void	ft_free_in_split(t_data *data, int line, char *str)
{
	while (line >= 0)
	{
		free(data->file_content[line]);
		line--;
	}
	if (str)
		free(str);
	ft_error(data, "Allocation failed");
}

void	ft_fill_split(t_data *data, char *str)
{
	int	line;
	int	i;

	i = 0;
	line = 0;
	while (str[i])
	{
		data->file_content[line] = \
		ft_add_char_to_string(data->file_content[line], str[i]);
		if (data->file_content[line] == NULL)
			ft_free_in_split(data, line, str);
		if (str[i] == '\n')
			line++;
		i++;
	}
	data->file_content[line + 1] = 0;
}

void	ft_split_cub(t_data *data, char *str)
{
	int	count;

	count = ft_count_line_file(data, str);
	data->file_content = (char **)malloc(sizeof(char *) * (count + 1));
	if (!data->file_content)
		ft_error(data, "Allocation failed");
	ft_fill_split(data, str);
}
