/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:36:27 by dcorenti          #+#    #+#             */
/*   Updated: 2022/12/13 14:17:06 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	This file contains the free functions who's free all data structure
*/

void	ft_free_matrice(char **matrice)
{
	int	i;

	i = 0;
	if (!matrice)
		return ;
	while (matrice[i])
	{
		if (matrice[i])
			free(matrice[i]);
		i++;
	}
	if (matrice)
		free(matrice);
}

void	ft_free_img(t_img *img)
{
	if (img)
	{
		if (img->relative_path)
			free(img->relative_path);
		free(img);
	}
}

void	ft_free_str(char *str)
{
	if (str)
		free(str);
}

void	ft_free_data(t_data *data)
{
	if (data)
	{
		ft_free_img(data->north_texture);
		ft_free_img(data->south_texture);
		ft_free_img(data->east_texture);
		ft_free_img(data->west_texture);
		ft_free_matrice(data->map);
		ft_free_str(data->north_path);
		ft_free_str(data->south_path);
		ft_free_str(data->east_path);
		ft_free_str(data->west_path);
		if (data->player)
			free(data->player);
		if (data->ceilling_color)
			free(data->ceilling_color);
		if (data->floor_color)
			free(data->floor_color);
		free(data);
	}
}
