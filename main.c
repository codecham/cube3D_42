/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:59:21 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 22:56:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

/*

	Pour les tests j'ai fais une petite fonction ft_for_test et create_map dans laquelle je remplis la structure avec des données brutes.
	Je l'ai commentée ici pour que ce soit toi qui remplisse cette strucutre avec les donnée du fichier .cub

*/

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
	exec(data);
}