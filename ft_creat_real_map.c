/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_real_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:40:55 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/25 22:41:06 by bsirikam         ###   ########.fr       */
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
		free(sarabun->map);
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
	// for (int i = 0; i < sarabun->hight; i++)
	// {
	// 	printf("|i = %d| %s", i, sarabun->map_play[i]);
	// }
	ft_render(map_real, sarabun);
}
