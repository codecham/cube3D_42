/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:52:17 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 05:46:29 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
Ce fichier contient une fonction qui va vérifier:
- Si le nombre d'argument est correct
- Si le format du fichier est bien .cub
- Si c'est un fichier qui peut se lire.

Je pense qu'on peut l'utiliser dans le debut du main :-)
*/


/* check the command line argument */
void	check_argument(int argc, char **argv, int *fd)
{
	int	len;

	if (argc != 2)
	{
		ft_printf("Error\nIncorrect number of arguments\n");
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if (argv[1][len - 1] != 'b' || argv[1][len - 2] != 'u' \
		|| argv[1][len - 3] != 'c' || argv[1][len - 4] != '.')
	{
		ft_printf("Error\nInvalid file format\n");
		exit(1);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
}
