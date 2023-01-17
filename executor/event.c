/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:21:21 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/17 20:49:04 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int close_click(t_data *data)
{
	ft_exit(data);
	return(0);
}

int key_release(int key_code, t_data *data)
{
	if (key_code == KEY_UP)
		data->move_up = 0;
	if (key_code == KEY_DOWN)
		data->move_down = 0;
	if (key_code == KEY_LEFT)
		data->move_left = 0;
	if (key_code == KEY_RIGHT)
		data->move_right = 0;
	if (key_code == ROTATE_LEFT)
		data->rotate_left = 0;
	if (key_code == ROTATE_RIGHT)
		data->rotate_right = 0;

	return(0);
}

int key_press(int key_code, t_data *data)
{
	if (key_code == EXIT)
		ft_exit(data);
	if (key_code == KEY_UP)
		data->move_up = 1;
	if (key_code == KEY_DOWN)
		data->move_down = 1;
	if (key_code == KEY_LEFT)
		data->move_left = 1;
	if (key_code == KEY_RIGHT)
		data->move_right = 1;
	if (key_code == ROTATE_LEFT)
		data->rotate_left = 1;
	if (key_code == ROTATE_RIGHT)
		data->rotate_right = 1;
	return(0);
}

void	event(t_data *data)
{
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 0, close_click, data);
	mlx_loop_hook(data->mlx, run, data);
	mlx_loop(data->mlx);	
}