/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mp_utils_II.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:00:46 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/01 18:27:44 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(t_data data)
{
	int		i;
	int		j;
	char	*first;
	char	*last;
	char	*line;

	i = 0;
	while (data.map[i])
		i++;
	first = data.map[0];
	last = data.map[--i];
	line = ft_strjoin(first, last);
	j = 0;
	while (line[j])
	{
		if (line[j] != '1')
		{
			free(line);
			return (0);
		}
		j++;
	}
	free(line);
	return (1);
}

int	check_columns(t_data data)
{
	int	i;
	int	line_size;
	int	j;

	line_size = ft_strlen(data.map[0]);
	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			if ((data.map[i][0] != '1') || (data.map[i][line_size - 1] != '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
