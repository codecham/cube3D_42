/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:37:51 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 21:24:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	print_maps(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 24)
	{
		while (j < 24)
		{
			if (i == 17 && j == 12)
				printf("N");
			else
				printf("%d", data->map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}


void	add_some_walls(t_data *data)
{
	data->map[10][10] = 1;
	data->map[11][10] = 1;
	data->map[12][10] = 1;
	data->map[13][10] = 1;
	data->map[14][10] = 1;
	data->map[10][11] = 1;
	data->map[10][12] = 1;
	data->map[10][13] = 1;
	data->map[11][13] = 1;
	data->map[12][13] = 1;
	data->map[13][13] = 1;
	data->map[14][13] = 1;
	data->map[4][1] = 1;
	data->map[4][2] = 1;
	data->map[4][3] = 1;
	data->map[4][5] = 1;
	data->map[5][1] = 1;
	data->map[5][2] = 1;
	data->map[5][3] = 1;
	data->map[5][4] = 1;
	data->map[5][5] = 1;
	data->map[5][6] = 1;
	data->map[5][7] = 1;
	data->map[20][20] = 1;
}

int	copy_line_in_map(t_data *data, int line, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			data->map[line][i] = 0;
		else
			data->map[line][i] = 1;
		i++;
	}
	if (i != 24)
		return (ERROR);
	return (SUCCESS);
}

int	create_map(t_data *data)
{
	int	i;

	i = 0;
	data->map = (int **)malloc(sizeof(int *) * 24);
	while (i < 24)
	{
		data->map[i] = (int *)malloc(sizeof(int) * 24);
		i++;
	}
	i = 1;
	if (copy_line_in_map(data, 0, "111111111111111111111111") == ERROR)
		return (ERROR);
	while (i < 23)
	{
		if (copy_line_in_map(data, i, "100000000000000000000001") == ERROR)
			return (ERROR);
		i++;
	}
	if (copy_line_in_map(data, i, "111111111111111111111111") == ERROR)
		return (ERROR);
	add_some_walls(data);
	print_maps(data);
	return (SUCCESS);
}
