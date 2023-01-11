/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:59:21 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/08 19:49:20 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube.h"

int main(int argc, char **argv)
{
	t_data	*data;
	
	(void)argc;
	(void)argv;
	data = (t_data *)malloc(sizeof(t_data));
	init(data);
	if (create_map(data) == ERROR)
	{
		printf("MAP ERROR\n");
		exit(0);
	}
	exec(data);
}