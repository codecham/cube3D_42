/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tab_to_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:59:31 by dcorenti          #+#    #+#             */
/*   Updated: 2023/01/20 18:36:19 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

char	*swap_tab_to_space(t_data *data, char *str, int i, int j)
{
	char	*new;

	while (str[i])
	{
		if (str[i] == '\t')
		{
			while (j < TAB_SIZE)
			{
				new = ft_realloc_add(new, ' ');
				if (!new)
					ft_error(data, "Allocation failed");
				j++;
			}
			j = 0;
		}
		else
		{
			new = ft_realloc_add(new, str[i]);
			if (!new)
				ft_error(data, "Allocation failed");
		}
		i++;
	}
	return (new);
}
