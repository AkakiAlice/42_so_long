/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:43:35 by alida-si          #+#    #+#             */
/*   Updated: 2022/02/26 04:02:02 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_args(int argc, char *argv)
{
	if (argc != 2)
		return (error_msg("invalid number of arguments"));
	if (ft_strrncmp(argv, ".ber", 4) == 0)
		return (error_msg("invalid file extension"));
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

int	valid_items(t_data data)
{
	if (shape_check(data) == 0)
		return (error_msg("invalid map shape"));
	if (count_item(data, 'P') != 1)
		return (error_msg("the map must contain 1 player"));
	if (count_item(data, 'E') != 1)
		return (error_msg("the map must contain 1 exit"));
	if (count_item(data, 'C') < 1)
		return (error_msg("the map must contain at least 1 collectible"));
	if (check_walls(data) == 0)
		return (error_msg("the map must be closed/surrounded by walls"));
	if (invalid_char(data) > 0)
		return (error_msg("the map contains invalid characters"));
	return (1);
}

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

int	check_walls(t_data data)
{
	if ((check_line(data) == 0) || (check_columns(data) == 0))
		return (0);
	return (1);
}

/*int	line_count(char **ptr)
{
	int i;

	i = 0;
	while(ptr[i])
		i++;
	return(i);
}

int	column_count(char **ptr)
{
	int	i;
	int	j;
	int	nb_colum;

	i = 0;
	while (ptr[0][i])
		i++;
	return (i);
}*/