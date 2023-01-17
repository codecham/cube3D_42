/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_pixl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:52:22 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/16 20:38:19 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	set_tex_pixl(t_data *data, t_tex *img)
{
	if (img->width * data->tex_y + data->tex_x < (img->width * img->height))
		data->color = img->addr[img->width * data->tex_y + data->tex_x];
}

void	get_tex_pixl(t_data *data)
{
	if (data->wall_text == NORTH)
		set_tex_pixl(data, data->text_north);
	else if (data->wall_text == SOUTH)
		set_tex_pixl(data, data->text_south);
	else if (data->wall_text == EAST)
		set_tex_pixl(data, data->text_east);
	else if (data->wall_text == WEST)
		set_tex_pixl(data, data->text_west);
}