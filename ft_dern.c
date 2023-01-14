/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:41:45 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/14 21:16:19 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dern(t_map *m, int r, int c)
{
	mlx_put_image_to_window(m->mlx, m->win, m->floor, m->p_pos_r * 64, \
	m->p_pos_c * 64);
	m->p_pos_r = r;
	m->p_pos_c = c;
	mlx_put_image_to_window(m->mlx, m->win, m->floor, m->p_pos_r * 64, \
	m->p_pos_c * 64);
	mlx_put_image_to_window(m->mlx, m->win, m->exit, m->c_e * 64, \
	m->r_e * 64);
	mlx_put_image_to_window(m->mlx, m->win, m->player, m->p_pos_r * 64, \
	m->p_pos_c * 64);
	return ;
}
