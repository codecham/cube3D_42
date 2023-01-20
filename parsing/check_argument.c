/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:52:17 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/20 05:53:40 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

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
	if (len < 5)
	{
		ft_printf("Error\nInvalid file format\n");
		exit(1);
	}
	if (argv[1][len - 1] != 'b' || argv[1][len - 2] != 'u' \
		|| argv[1][len - 3] != 'c' || argv[1][len - 4] != '.')
	{
		ft_printf("Error\nInvalid file format\n");
		exit(1);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd < 0)
	{
		ft_printf("Error\n%s: No such file or directory\n", argv[1]);
		exit(1);
	}
}
