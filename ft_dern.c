/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:41:45 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/08 00:49:08 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dern(t_map *m, int r, int c)
{
	ft_printf("p_pos_r = %d p_pos_c = %d\n", m->p_pos_r, m->p_pos_c);
	// ft_printf("%c\n", m->map[c][r]);
	// if (m->map[c][r] == 'E')
	// {
	// 	mlx_put_image_to_window(m->mlx, m->win, m->floor, m->p_pos_c * 64, \
	// 	m->p_pos_r * 64);
	// 	mlx_put_image_to_window(m->mlx, m->win, m->exit, m->p_pos_c * 64, \
	// 	m->p_pos_r * 64);
	// }
	mlx_put_image_to_window(m->mlx, m->win, m->floor, m->p_pos_r * 64, \
		m->p_pos_c * 64);
	ft_printf("r = %d c = %d\n", r, c);
	m->p_pos_r = r;
	m->p_pos_c = c;
	mlx_put_image_to_window(m->mlx, m->win, m->floor, m->p_pos_r * 64, \
	m->p_pos_c * 64);
	// mlx_put_image_to_window(m->mlx, m->win, m->exit, m->p_pos_r * 64, \
	// m->p_pos_c * 64);
	mlx_put_image_to_window(m->mlx, m->win, m->player, m->p_pos_r * 64, \
	m->p_pos_c * 64);
	return ;
}
