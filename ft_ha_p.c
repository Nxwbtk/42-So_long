/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ha_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:54:45 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/14 20:13:01 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ha_p(t_sarabun *sarabun)
{
	int	x;
	int	y;

	x = 0;
	while (sarabun->map[x])
	{
		y = 0;
		while (sarabun->map[x][y] != '\n' && sarabun->map[x][y])
		{
			if (sarabun->map[x][y] == 'P')
			{
				sarabun->p_pos_r = x;
				sarabun->p_pos_c = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	ft_ha_e(t_sarabun *sarabun, t_map *real_map)
{
	int	x;
	int	y;

	x = 0;
	while (sarabun->map[x])
	{
		y = 0;
		while (sarabun->map[x][y] != '\n' && sarabun->map[x][y])
		{
			if (sarabun->map[x][y] == 'E')
			{
				real_map->r_e = x;
				real_map->c_e = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
