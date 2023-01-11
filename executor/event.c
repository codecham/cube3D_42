/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:21:21 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/10 22:08:04 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int close_click(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	return(0);
}

int key_release(int key_code, t_data *data)
{
	(void)key_code;
	(void)data;

	return(0);
}

int key_press(int key_code, t_data *data)
{
	if (key_code == EXIT)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else
		move(data, key_code);
	return(0);
}

void	event(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 0, close_click, data);
	mlx_loop_hook(data->mlx, run, data);
	mlx_loop(data->mlx);	
}