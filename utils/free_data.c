/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:46:48 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/20 05:14:06 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

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

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (i < data->map_height)
		{
			if (data->map[i])
				free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

void	destroy_images(t_data *data)
{
	if (data->game_img->img)
		mlx_destroy_image(data->mlx, data->game_img->img);
	if (data->text_north->img)
		mlx_destroy_image(data->mlx, data->text_north->img);
	if (data->text_south->img)
		mlx_destroy_image(data->mlx, data->text_south->img);
	if (data->text_east->img)
		mlx_destroy_image(data->mlx, data->text_east->img);
	if (data->text_west->img)
		mlx_destroy_image(data->mlx, data->text_west->img);
	if (data->game_img)
		free(data->game_img);
	if (data->text_north)
		free(data->text_north);
	if (data->text_south)
		free(data->text_south);
	if (data->text_east)
		free(data->text_east);
	if (data->text_west)
		free(data->text_west);
}

void	free_data(t_data *data)
{
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	if (data->path_north)
		free(data->path_north);
	if (data->path_south)
		free(data->path_south);
	if (data->path_east)
		free(data->path_east);
	if (data->path_west)
		free(data->path_west);
	destroy_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->file_content)
		ft_free_matrice(data->file_content);
	if (data->map)
		ft_free_map(data);
}
