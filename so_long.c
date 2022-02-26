/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:38:58 by alida-si          #+#    #+#             */
/*   Updated: 2022/02/26 04:23:45 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_line(char *temp)
{
	int	i;

	i = 0;
	if (temp[i] == '\0')
	{
		free (temp);
		return (0);
	}
	while (temp[i])
	{
		if ((temp[i] == '\n') && (temp[++i] == '\n'))
		{
			free(temp);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**create_matrix(char *file_name)
{
	int		fd;
	char	*ret;
	char	*swap;
	char	*temp;
	char	**map;

	fd = open(file_name, O_RDONLY);
	temp = ft_strdup("");
	while (1)
	{
		ret = get_next_line(fd);
		if (!ret)
			break ;
		swap = temp;
		temp = ft_strjoin(swap, ret);
		free(swap);
		free(ret);
	}
	if (!valid_line(temp))
		return (NULL);
	map = ft_split(temp, '\n');
	close(fd);
	free(temp);
	return (map);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!(check_args(argc, argv[1])))
		return (1);
	data.map = create_matrix(argv[1]);
	if (data.map == NULL)
	{
		ft_printf("Error, unable to create map\n");
		free_matrix(data.map);
		return (1);
	}
	if (!(valid_items(data)))
	{
		free_matrix(data.map);
		return (1);
	}
	free_matrix(data.map);
	return (0);
}