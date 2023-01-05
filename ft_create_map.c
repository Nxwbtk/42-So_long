/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:42:18 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/06 04:51:41 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(char *av, t_sarabun *sarabun)
{
	int		fd;
	int		high;
	t_map	*map_real;

	fd = open(av, O_RDONLY);
	sarabun->map = malloc(sizeof(char *) * (sarabun->hight + 1));
	high = 0;
	while (high < sarabun->hight)
	{
		sarabun->map[high] = get_next_line(fd);
		high++;
	}
	sarabun->map[high] = NULL;
	close(fd);
	ft_check_frame(sarabun);
	ft_ha_p(sarabun);
	sarabun->num_c = 0;
	sarabun->num_e = 0;
	ft_flood_fill(sarabun->map, sarabun, sarabun->p_pos_r, sarabun->p_pos_c);
	check_c_e(sarabun);
	ft_free_map(sarabun);
	map_real = (t_map *)malloc(sizeof(t_map));
	ft_create_real_map(map_real, sarabun, av);
}

void	ft_free_map(t_sarabun *sarabun)
{
	int	x;

	x = 0;
	while (sarabun->map[x])
	{
		free(sarabun->map[x]);
		x++;
	}
	free(sarabun->map);
}
