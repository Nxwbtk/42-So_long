/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_real_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:40:55 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/13 04:14:53 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_real_map(t_map *map_real, t_sarabun *sarabun, char *av)
{
	int	i;
	int	fd;

	i = 0;
	map_real->map = (char **)malloc(sizeof(char *) * (sarabun->hight + 1));
	if (!map_real->map)
	{
		ft_printf("Error\nMalloc failed");
		free(map_real);
		free(sarabun->map);
		free(sarabun);
		exit(1);
	}
	fd = open(av, O_RDONLY);
	while (i < sarabun->hight)
	{
		map_real->map[i] = get_next_line(fd);
		i++;
	}
	map_real->map[i] = NULL;
	close(fd);
	ft_render(map_real, sarabun);
}
