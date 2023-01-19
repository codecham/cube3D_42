/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:59:21 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 05:11:24 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

/*

	Pour les tests j'ai fais une petite fonction ft_for_test et create_map dans laquelle je remplis la structure avec des données brutes.
	Je l'ai commentée ici pour que ce soit toi qui remplisse cette strucutre avec les donnée du fichier .cub

*/

void	print_matrice(t_data *data)
{
	int i;

	i = 0;
	while (data->file_content[i])
	{
		printf("%s", data->file_content[i]);
		i++;
	}
}

void	print_structure(t_data *data)
{
	printf("\n\n");
	printf("Path_north = %s\n", data->path_north);
	printf("Path_south = %s\n", data->path_south);
	printf("Path_east = %s\n", data->path_east);
	printf("Path_west = %s\n", data->path_west);
	printf("Floor->r = %d\n", data->floor->r);
	printf("Floor->g = %d\n", data->floor->g);
	printf("Floor->b = %d\n", data->floor->b);
	printf("Ceiling->r = %d\n", data->ceiling->r);
	printf("Ceiling->g = %d\n", data->ceiling->g);
	printf("Ceiling->b = %d\n", data->ceiling->b);
}

void	ft_for_test(t_data *data)
{
	data->pos_x = 5.5;
	data->pos_y = 7.5;
	data->dir_x = 0;
	data->dir_y = -0.99;
	data->plane_x = -0.80;
	data->plane_y = 0;
	data->hit = 0;
	data->side = 0;
	data->screen_height = SCREEN_HEIGHT;
	data->screen_width = SCREEN_WIDTH;
	data->ceiling->r = 0;
	data->ceiling->g = 0;
	data->ceiling->b = 150;
	data->floor->r = 0;
	data->floor->g = 150;
	data->floor->b = 0;
	data->path_north = ft_strdup("./textures/blue.xpm");
	data->path_south = ft_strdup("./textures/bricks_yellow.xpm");
	data->path_east = ft_strdup("./textures/grey.xpm");
	data->path_west = ft_strdup("./textures/wood.xpm");
}


int main(int argc, char **argv)
{
	t_data	*data;
	int		fd;
	
	check_argument(argc, argv, &fd);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_error(NULL, "Allocation failed");
	init(data);
	if (malloc_all(data) == ERROR)
		ft_error(data, "Allocation failed");
	parsing(data, fd);
	print_matrice(data);
	print_structure(data);
	ft_exit(data);
	// ft_for_test(data);
	// if (create_map(data) == ERROR)
	// 	ft_error(data, "Map error");
	/*
		code pour le parsing. 
	*/
	exec(data);
}