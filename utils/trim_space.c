/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 03:07:09 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 05:02:41 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

char	*trim_space(char *str)
{
	char *new;

	new = ft_strtrim(str, " \n");
	if (!new)
		return (NULL);
	if (str)
		free(str);
	return (new);
}
