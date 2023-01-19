/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:36:17 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 00:02:47 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(char *save, int i)
{
	char	*new;

	while (save && save[i] && save[i] != '\n')
		i++;
	if (is_line(save) >= 0)
		i++;
	if (i == 0)
		return (NULL);
	new = (char *)malloc(sizeof(char) * i + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (save && save[i] && save[i] != '\n')
	{
		new[i] = save[i];
		i++;
	}
	if (is_line(save) >= 0)
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	*join(char *save, char *tmp, int lu)
{
	int		i;
	int		j;
	char	*new;

	i = ft_strlen_gnl(save);
	j = 0;
	new = (char *)malloc(sizeof(char) * i + lu + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (save && save[i])
	{
		new[i] = save[i];
		i++;
	}
	while (j < lu)
	{
		new[i + j] = tmp[j];
		j++;
	}
	new[i + j] = '\0';
	if (save)
		free(save);
	return (new);
}

static char	*update_line(char *save)
{
	char	*new;
	int		i;
	int		j;

	i = is_line(save);
	j = 0;
	if (i < 0)
	{
		if (i == -1)
			free(save);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * ft_strlen_gnl(save) - i + 1);
	if (!new)
		return (NULL);
	i++;
	while (save[i + j])
	{
		new[j] = save[i + j];
		j++;
	}
	new[j] = '\0';
	if (save)
		free(save);
	return (new);
}

static char	*get_next_line_ext(int fd, char *line, int lu)
{
	static char	*save;
	char		tmp[BUFFER_SIZE + 1];

	if (read(fd, line, 0) < 0)
		return (ft_error_gnl(save));
	if (is_line(save) < 0)
	{
		lu = read(fd, tmp, BUFFER_SIZE);
		while (is_line(save) < 0 && lu > 0)
		{
			save = join(save, tmp, lu);
			if (!save)
				return (ft_error_gnl(save));
			if (is_line(save) < 0 && lu >= 0)
				lu = read(fd, tmp, BUFFER_SIZE);
		}
	}
	line = get_line(save, 0);
	if (line == NULL)
		return (ft_error_gnl(save));
	save = update_line(save);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		lu;

	line = NULL;
	lu = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (ft_error_gnl(0));
	return (get_next_line_ext(fd, line, lu));
}
