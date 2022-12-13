/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:34:00 by dcorenti          #+#    #+#             */
/*   Updated: 2022/12/13 14:22:49 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

/*
	This file will contains the error functions.

		ft_error_free free the data strcuture, print the message followed
		by a newline and return -1; 

		ft_error just print the error message followed by a newline
		and return -1;
*/

int	ft_error_free(t_data *data, char *message)
{
	ft_free_data(data);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	return (-1);
}

int	ft_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	return (-1);
}
