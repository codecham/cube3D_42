/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:28:41 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 22:01:21 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	set_default_value(t_data *data, int line)
{
	int	i;

	i = 0;
	while (i < data->map_width)
	{
		data->map[line][i] = -1;
		i++;
	}
}

void	malloc_map(t_data *data)
{
	int	i;

	i = 0;
	data->map = (int **)malloc(sizeof(int *) * data->map_height);
	if (!data->map)
		ft_error(data, "Allocation error");
	while (i < data->map_height)
	{
		data->map[i] = NULL;
		data->map[i] = (int *)malloc(sizeof(int) * data->map_width);
		if (!data->map[i])
			ft_error(data, "Allocation failed");
		set_default_value(data, i);
		i++;
	}
}
