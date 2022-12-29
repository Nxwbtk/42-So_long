/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:52:00 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/29 21:52:01 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close(t_map *real_map)
{
	mlx_destroy_window(real_map->mlx, real_map->win);
	ft_free_render(real_map);
	exit(1);
}