/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:34:40 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/20 05:50:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	check_dup_alloc(t_data *data, int identifer)
{
	if (identifer == NORTH)
	{
		if (data->path_north == NULL)
			ft_error(data, "Allocation Failed");
	}
	else if (identifer == SOUTH)
	{
		if (data->path_south == NULL)
			ft_error(data, "Allocation Failed");
	}
	else if (identifer == EAST)
	{
		if (data->path_east == NULL)
			ft_error(data, "Allocation Failed");
	}
	else if (identifer == NORTH)
	{
		if (data->path_west == NULL)
			ft_error(data, "Allocation Failed");
	}
}
