/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:26:17 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/23 15:25:16 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

char	*ft_realloc_add(char *old, char c)
{
	int		i;
	char	*new;

	i = -1;
	if (!old)
	{
		old = (char *)malloc(sizeof(char) * 2);
		if (!old)
			return (NULL);
		old[0] = c;
		old[1] = '\0';
		return (old);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(old) + 2));
	if (!new)
		return (NULL);
	while (old[++i])
		new[i] = old[i];
	new[i] = c;
	new[i + 1] = '\0';
	if (old)
		free(old);
	return (new);
}
