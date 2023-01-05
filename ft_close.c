/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:52:00 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/06 04:42:33 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close(t_map *real_map)
{
	mlx_destroy_image(real_map->mlx, real_map->collect);
	mlx_destroy_image(real_map->mlx, real_map->exit);
	mlx_destroy_image(real_map->mlx, real_map->player);
	mlx_destroy_image(real_map->mlx, real_map->wall);
	mlx_destroy_image(real_map->mlx, real_map->floor);
	mlx_destroy_window(real_map->mlx, real_map->win);
	ft_free_render(real_map);
	exit(EXIT_SUCCESS);
}
