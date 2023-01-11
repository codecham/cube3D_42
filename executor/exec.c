/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:21:20 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/10 21:24:28 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	draw_form(t_data *data)
{
	int r;
	int g;
	int b;
	int x;
	int y;

	r = 0;
	b = 200;
	g = 0;
	x = 10;
	y = 10;
	data->hit = 0;
	while(x < 100)
	{
		while(y < 100)
		{
			my_mlx_pixel_put(data->game_img, x, y, create_trgb(0, r, g, b));
			y++;
		}
		x++;
		y = 10;
	}	
}

void	exec(t_data *data)
{
	minilibx_init(data);
	event(data);
}