/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color_in_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:55:05 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/20 05:49:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	error_color(t_data *data, char c)
{
	printf("Error\n");
	if (ft_isdigit(c))
		printf("RGB color need to be between 0 and 255\n");
	else
		printf("Wrong character is RGB value");
	ft_exit(data);
}

void	add_rgb(t_data *data, t_color *color, int value)
{
	if (value < 0 || value > 255)
		ft_error(data, "RGB color need to be between 0 and 255");
	if (color->r == -1)
		color->r = value;
	else if (color->g == -1)
		color->g = value;
	else
		color->b = value;
}

int	get_color(t_data *data, char *str, int i, int identifier)
{
	char	color[4];
	int		count;

	count = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && ft_isdigit(str[i]) && count < 3)
	{
		color[count] = str[i];
		count++;
		i++;
	}
	if (count == 0 && str[i])
		error_color(data, str[i]);
	color[count] = '\0';
	if (identifier == FLOOR)
		add_rgb(data, data->floor, ft_atoi(color));
	else
		add_rgb(data, data->ceiling, ft_atoi(color));
	return (i);
}

void	add_color_in_data(t_data *data, char *str, int identifier)
{
	int	i;
	int	count;

	i = 2;
	count = 0;
	while (str[i])
	{
		i = get_color(data, str, i, identifier);
		count++;
		if (str[i] && str[i] != ' ' && str[i] != ',')
			error_color(data, str[i]);
		if (count == 3 && str[i] == '\0')
			break ;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] != ',')
			error_color(data, str[i]);
		i++;
	}
}
