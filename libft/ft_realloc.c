/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 00:15:12 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/19 02:33:02 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int to_add)
{
	char	*new;
	int		len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
	}
	new = malloc(sizeof(char) * (len + to_add));
	if (new)
	{
		len = -1;
		if (str)
		{
			while (str[++len])
				new[len] = str[len];
		}
		new[len] = 0;
	}
	free(str);
	str = NULL;
	return (new);
}
