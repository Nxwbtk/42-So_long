/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:39:04 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/25 22:39:05 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render(t_map *real_map, t_sarabun *sarabun)
{
	real_map->mlx = mlx_init();
	real_map->win = mlx_new_window(real_map->mlx, (sarabun->len * 64) + 1, (sarabun->hight * 64) + 1, "Hi");
	mlx_loop(real_map->mlx);
}