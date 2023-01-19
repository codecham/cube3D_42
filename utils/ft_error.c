/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:35:49 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 20:25:41 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	ft_error(t_data *data, char *message)
{
	printf("Error\n");
	printf("%s\n", message);
	ft_exit(data);
}

void	ft_error_line(t_data *data, int line)
{
	printf("Error\n");
	printf("Line %d in cub file is not correct\n", line);
	ft_exit(data);
}

void	ft_error_map_wall(t_data *data)
{
	printf("Error\n");
	printf("Map is not closed by walls\n");
	ft_exit(data);
}

void	ft_error_map_small(t_data *data)
{
	printf("Error\n");
	printf("Map is too small\n");
	ft_exit(data);
}
