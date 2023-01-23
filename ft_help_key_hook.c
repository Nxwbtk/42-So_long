/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:12:15 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/23 23:12:18 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_left(t_map *real_map, int *r, int *c)
{
	if (test_walk(real_map, (*r) - 1, (*c)))
	{
		mlx_put_image_to_window(real_map->mlx, real_map->win, \
		real_map->floor, (*r) * 64, (*c) * 64);
		(*r)--;
		ft_dern(real_map, *r, *c);
	}
}

void	ft_up(t_map *real_map, int *r, int *c)
{
	if (test_walk(real_map, (*r), (*c) - 1))
	{
		mlx_put_image_to_window(real_map->mlx, real_map->win, \
		real_map->floor, (*r) * 64, (*c) * 64);
		(*c)--;
		ft_dern(real_map, *r, *c);
	}
}

void	ft_right(t_map *real_map, int *r, int *c)
{
	if (test_walk(real_map, (*r) + 1, (*c)))
	{
		mlx_put_image_to_window(real_map->mlx, real_map->win, \
		real_map->floor, (*r) * 64, (*c) * 64);
		(*r)++;
		ft_dern(real_map, *r, *c);
	}
}

void	ft_down(t_map *real_map, int *r, int *c)
{
	if (test_walk(real_map, (*r), (*c) + 1))
	{
		mlx_put_image_to_window(real_map->mlx, real_map->win, \
		real_map->floor, (*r) * 64, (*c) * 64);
		(*c)++;
		ft_dern(real_map, *r, *c);
	}
}
