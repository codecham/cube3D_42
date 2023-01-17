/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:07:37 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/17 21:13:35 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	ft_xpm_to_img(t_data *data, t_tex *tex, char *file)
{
	tex->img = mlx_xpm_file_to_image(data->mlx, file, &tex->width,
			&tex->height);
	if (!tex->img)
		return (ERROR);
	tex->addr = (int *)mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	if (!tex->addr)
		return (ERROR);
	return (SUCCESS);
}

int	ft_charge_textures(t_data *data)
{
	if (ft_xpm_to_img(data, data->text_north, data->path_north) == ERROR)
		return (ERROR);
	if (ft_xpm_to_img(data, data->text_south, data->path_south) == ERROR)
		return (ERROR);
	if (ft_xpm_to_img(data, data->text_east, data->path_east) == ERROR)
		return (ERROR);
	if (ft_xpm_to_img(data, data->text_west, data->path_west) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
