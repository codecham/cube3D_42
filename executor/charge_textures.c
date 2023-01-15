/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:07:37 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/14 18:08:49 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void ft_charge_xpm(t_data *data, char *file)
{
	t_img *img;
	
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return ;
	img->img = mlx_xpm_file_to_image(data->mlx, file, &img->width, &img->height);
	if (!img->img)
		return ;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	mlx_put_image_to_window(data->mlx, data->win, img, 0, 0);
	mlx_loop(data);
	if (!img->addr)
		return ;
}


// t_tex *ft_charge_xpm(t_data *data, char *file)
// {
// 	t_tex *tex;
	
// 	tex = (t_tex *)malloc(sizeof(t_tex));
// 	if (!tex)
// 		return(NULL);
// 	tex->img = mlx_xpm_file_to_image(data->mlx, file, &tex->width, &tex->height);
// 	if (!tex->img)
// 		return(NULL);
// 	tex->addr = (int *)mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line, &tex->endian);
// 	mlx_put_image_to_window(data->mlx, data->win, tex->img, 0, 0);
// 	mlx_loop(data);
// 	if (!tex->addr)
// 		return(NULL);
// 	return(tex);
// }

int	ft_charge_textures(t_data *data)
{
	// data->text_north = ft_charge_xpm(data, data->path_north);
	ft_charge_xpm(data, data->path_north);
	// if (ft_charge_xpm(data, data->text_south, data->path_south) == ERROR)
	// 	return(ERROR);
	// if (ft_charge_xpm(data, data->text_east, data->path_east) == ERROR)
	// 	return(ERROR);
	// if (ft_charge_xpm(data, data->text_west, data->path_west) == ERROR)
	// 	return(ERROR);
	return(SUCCESS);
}
