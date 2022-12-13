/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:02:26 by dcorenti          #+#    #+#             */
/*   Updated: 2022/12/13 14:18:10 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	This file contains function who's allocate memory for the data structure

	PARAMETERS: The data strucure

	RETURN VALUES:
		
		Return the data structure if everything is ok.
		Return NULL if an allocation failed
*/

int	ft_malloc_img(t_data *data)
{
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->west_texture = NULL;
	data->east_texture = NULL;
	data->north_texture = (t_img *)malloc(sizeof(t_img));
	data->south_texture = (t_img *)malloc(sizeof(t_img));
	data->west_texture = (t_img *)malloc(sizeof(t_img));
	data->east_texture = (t_img *)malloc(sizeof(t_img));
	if (!data->north_texture || !data->south_texture
		|| !data->west_texture || !data->east_texture)
		return (-1);
	return (0);
}

int	ft_malloc_player(t_data *data)
{
	data->player = NULL;
	data->player = (t_player *)malloc(sizeof(t_player));
	if (!data->player)
		return (-1);
	return (0);
}

int	ft_malloc_color(t_data *data)
{
	data->floor_color = NULL;
	data->ceilling_color = NULL;
	data->floor_color = (t_color *)malloc(sizeof(t_color));
	data->ceilling_color = (t_color *)malloc(sizeof(t_color));
	if (!data->floor_color || !data->ceilling_color)
		return (-1);
	return (0);
}

t_data *ft_malloc_data(void)
{
	t_data	*data;
	
	data = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	if (ft_malloc_img(data) == -1)
		return (NULL);
	if (ft_malloc_player(data) == -1)
		return (NULL);
	if (ft_malloc_color(data) == -1)
		return (NULL);
	return (data);
}
