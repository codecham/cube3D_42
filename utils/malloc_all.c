/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:23:21 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/15 18:23:51 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	Fonction qui alloue les strucutures couleurs aisni que la game_img qui sera l'image de notre
	jeu sur laquelle on dessine avant de l'afficher à l'écran 
*/

int	malloc_color(t_data *data)
{
	data->floor = NULL;
	data->ceiling = NULL;
	data->floor = (t_color *)malloc(sizeof(t_color));
	data->ceiling = (t_color *)malloc(sizeof(t_color));
	data->w_north = (t_color *)malloc(sizeof(t_color)); 	// FOR TEST, A DELETE
	data->w_south = (t_color *)malloc(sizeof(t_color));		// FOR TEST, A DELETE
	data->w_east = (t_color *)malloc(sizeof(t_color));		// FOR TEST, A DELETE
	data->w_west = (t_color *)malloc(sizeof(t_color));		// FOR TEST, A DELETE
	if (!data->floor || !data->ceiling)
		return(ERROR);
	return(SUCCESS);
}

int malloc_img(t_data *data)
{
	data->game_img = (t_img *)malloc(sizeof(t_img));
	if (!data->game_img)
		return(ERROR);
	return(SUCCESS);
}

int	malloc_all(t_data *data)
{
	if (malloc_color(data) == ERROR)
		return(ERROR);
	if (malloc_img(data) == ERROR)
		return(ERROR);
	return(SUCCESS);
}
