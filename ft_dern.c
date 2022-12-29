/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:41:45 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/29 22:42:36 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dern(t_map *m, int r, int c)
{
	if (m->map[m->p_pos_r][m->p_pos_c] == 'E')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->floor, m->p_pos_r * 64, \
		m->p_pos_c * 64);
	}
}