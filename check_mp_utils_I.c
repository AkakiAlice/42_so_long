/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_I.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:21:46 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/01 18:22:23 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shape_check(t_data data)
{
	int	i;
	int	line_size;
	int	aux;

	line_size = ft_strlen(data.map[0]);
	i = 1;
	while (data.map[i])
	{
		aux = ft_strlen(data.map[i]);
		if (aux != line_size)
			return (0);
		i++;
	}
	return (1);
}

int	count_item(t_data data, char item)
{
	int	i;
	int	j;
	int	nb_item;

	nb_item = 0;
	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] == item)
				nb_item++;
			j++;
		}
		i++;
	}
	return (nb_item);
}

int	check_walls(t_data data)
{
	if ((check_line(data) == 0) || (check_columns(data) == 0))
		return (0);
	return (1);
}

int	invalid_char(t_data data)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if ((data.map[i][j] != 'P') && (data.map[i][j] != 'C')
				&& (data.map[i][j] != 'E') && (data.map[i][j] != '0')
				&& (data.map[i][j] != '1'))
				c++;
			j++;
		}
		i++;
	}
	return (c);
}
