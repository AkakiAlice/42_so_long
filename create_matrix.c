/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:08:51 by alida-si          #+#    #+#             */
/*   Updated: 2022/03/02 18:45:14 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	valid_line(char *temp)
{
	int	i;
	int	j;

	j = ft_strlen(temp);
	i = 0;
	if (temp[i] == '\0' || temp[i] == '\n')
	{
		free (temp);
		ft_printf("Error, unable to create map\n");
		return (0);
	}
	while (temp[i])
	{
		if ((temp[i] == '\n') && (temp[++i] == '\n') || temp[j - 1] == '\n')
		{
			free(temp);
			ft_printf("Error, unable to create map\n");
			return (0);
		}
		i++;
	}
	return (1);
}
