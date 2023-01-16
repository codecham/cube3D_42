/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:59:21 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/16 04:04:37 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

/*

	Pour les tests j'ai fais une petite fonction ft_for_test et create_map dans laquelle je remplis la structure avec des données brutes.
	Je l'ai commentée ici pour que ce soit toi qui remplisse cette strucutre avec les donnée du fichier .cub

*/

void	ft_for_test(t_data *data)
{
	data->pos_x = 5;
	data->pos_y = 7;
	data->dir_x = 0;
	data->dir_y = -0.99;
	data->plane_x = -0.80;
	data->plane_y = 0;
	data->hit = 0;
	data->side = 0;
	data->screen_height = screenHeight;
	data->screen_width = screenWidth;
	data->w_north->r = 0;
	data->w_north->g = 0;
	data->w_north->b = 255;
	data->w_south->r = 255;
	data->w_south->g = 0;
	data->w_south->b = 0;
	data->w_east->r = 252;
	data->w_east->g = 255;
	data->w_east->b = 38;
	data->w_west->r = 0;
	data->w_west->g = 255;
	data->w_west->b = 0;
	data->ceiling->r = 0;
	data->ceiling->g = 0;
	data->ceiling->b = 0;
	data->floor->r = 0;
	data->floor->g = 0;
	data->floor->b = 0;
	data->path_north = ft_strdup("./textures/bricks_red.xpm");
	data->path_south = ft_strdup("./textures/bricks_blue.xpm");
	data->path_east = ft_strdup("./textures/bricks_green.xpm");
	data->path_west = ft_strdup("./textures/bricks_yellow.xpm");
}


int main(int argc, char **argv)
{
	t_data	*data;
	
	(void)argc;
	(void)argv;
	data = (t_data *)malloc(sizeof(t_data));
	init(data);
	if (malloc_all(data) == ERROR)
		ft_error(data, "Malloc error");
	// ft_for_test(data);
	// if (create_map(data) == ERROR)
	// 	ft_error(data, "Map error");
	/*
		code pour le parsing. 
	*/
	exec(data);
}