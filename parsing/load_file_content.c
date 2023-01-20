/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:04:57 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/20 16:25:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*

	This function read in the file and copy all content in
	char **data->file_content.

	First we read and stock all the line of our file in a sigle line (char *str)

	Second we split the restult with a split function.
	Split is pretty much the same that the lbift's one but without delete the
	split's character.

	At the end we have all the file in the data->file_content, we can work on it!

*/

char	*load_in_string(int fd)
{
	char	*str;
	char	*tmp;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	str = ft_strdup(tmp);
	if (!str)
	{
		free(tmp);
		return (NULL);
	}
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (tmp != NULL)
		{
			str = ft_add_string(str, tmp);
			if (!str)
				return (NULL);
		}
	}
	return (str);
}

void	load_file_content(t_data *data, int fd)
{
	char	*str;

	str = load_in_string(fd);
	close(fd);
	if (str == NULL)
		ft_error(data, "Failed to reading configuration file");
	ft_split_cub(data, str);
	free(str);
}
