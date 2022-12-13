/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:22:32 by dcorenti          #+#    #+#             */
/*   Updated: 2022/12/13 14:23:32 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

int main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	if (argc != 2)
		return (ft_error("Wrong number of arguments"));
	data = ft_malloc_data();
	if (!data)
		return (ft_error_free(data, "Malloc error"));
	ft_init(data);
	/*
		all functions for run program
	*/
	ft_free_data(data);
}