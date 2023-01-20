/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:59:21 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/20 18:06:49 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

int	main(int argc, char **argv)
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
