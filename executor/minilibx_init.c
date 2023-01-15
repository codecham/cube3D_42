/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 05:38:09 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/15 16:52:16 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	mlx_img_init(t_data *data)
{
	data->game_img->img = mlx_new_image(data->mlx, screenWidth, screenHeight);
	data->game_img->addr = mlx_get_data_addr(data->game_img->img, &data->game_img->bits_per_pixel,
		&data->game_img->line_length, &data->game_img->endian);
	return (SUCCESS);
}

int	minilibx_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return(ERROR);
	data->win = mlx_new_window(data->mlx, screenWidth, screenHeight, "cube");
	if (!data->win)
		return(ERROR);
	if (mlx_img_init(data) != SUCCESS)
		return(ERROR);
	// if (ft_charge_textures(data) != SUCCESS)
	// 	return(ERROR);
	return(SUCCESS);
}
