/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:38:58 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/01 18:18:20 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.map = create_matrix(argv[1]);
	if (data.map == NULL)
		return (1);
	ft_printf("criou mapa: %s\n", data.map[0]);
	if (!valid_map(data, argc, argv[1]))
		return (1);
	free_matrix(data.map);
	return (0);
}
