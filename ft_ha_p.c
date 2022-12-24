/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ha_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:54:45 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/24 22:13:46 by bsirikam         ###   ########.fr       */
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
