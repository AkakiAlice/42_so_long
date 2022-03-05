/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:43:35 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/05 21:06:56 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(t_data data)
{
	if (!(check_items(data)))
	{
		free_matrix(data.map);
		return (0);
	}
	return (1);
}

int	check_args(int argc, char *argv)
{
	if (argc != 2)
		return (error_msg("invalid number of arguments"));
	if (ft_strrncmp(argv, ".ber", 4) == 0)
		return (error_msg("invalid file extension"));
	return (1);
}

int	check_items(t_data data)
{
	if (shape_check(data) == 0)
		return (error_msg("invalid map shape"));
	if (invalid_char(data) > 0)
		return (error_msg("the map contains invalid characters"));
	if (check_walls(data) == 0)
		return (error_msg("the map must be closed/surrounded by walls"));
	if (count_item(data, 'P') != 1)
		return (error_msg("the map must contain 1 player"));
	if (count_item(data, 'E') != 1)
		return (error_msg("the map must contain 1 exit"));
	if (count_item(data, 'C') < 1)
		return (error_msg("the map must contain at least 1 collectible"));
	return (1);
}
