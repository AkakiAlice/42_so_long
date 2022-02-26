/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:39:50 by alida-si          #+#    #+#             */
/*   Updated: 2022/02/26 02:00:55 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_msg(char *error_str)
{
	ft_printf("Error, %s\n", error_str);
	return (0);
}

void	free_matrix(char **ptr)
{
	int	i;

	if (ptr != NULL)
	{
		i = 0;
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
}
