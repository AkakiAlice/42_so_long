/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:38:58 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/05 21:16:52 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_args(argc, argv[1]) == 1)
	{
		data.map = create_matrix(argv[1]);
		if (data.map == NULL)
			return (1);
		if (!valid_map(data))
			return (1);
		init_game(&data);
		return (0);
	}
	return (1);
}
