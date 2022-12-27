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
	real_map->win = mlx_new_window(real_map->mlx, (sarabun->len - 1) * 64, \
	(sarabun->hight * 64) + 1, "42Bangkok Armel's Adventure");
	real_map->wall = mlx_xpm_file_to_image(real_map->mlx, "./img/wall64.xpm", \
	&sarabun->len, &sarabun->hight);
	real_map->floor = mlx_xpm_file_to_image(real_map->mlx, "./img/floor64.xpm", \
	&sarabun->len, &sarabun->hight);
	real_map->player = mlx_xpm_file_to_image(real_map->mlx, "./img/Armel64.xpm", \
	&sarabun->len, &sarabun->hight);
	real_map->collect = mlx_xpm_file_to_image(real_map->mlx, "./img/collect.xpm", \
	&sarabun->len, &sarabun->hight);
	real_map->exit = mlx_xpm_file_to_image(real_map->mlx, "./img/Exit64.xpm", \
	&sarabun->len, &sarabun->hight);
	ft_floor(real_map, sarabun);
	ft_wall(real_map);
	mlx_loop(real_map->mlx);
	ft_free_render(real_map);
}

void	ft_wall(t_map *real_map)
{
	int	h;
	int	l;

	h = 0;
	l = 0;
	while (real_map->map[h])
	{
		l = 0;
		while (real_map->map[h][l] != '\0' && real_map->map[h][l] != '\n')
		{
			if (real_map->map[h][l] == '1')
			{
				mlx_put_image_to_window(real_map->mlx, real_map->win, \
				real_map->wall, l * 64, h * 64);
			}
			if (real_map->map[h][l] == 'P')
			{
				mlx_put_image_to_window(real_map->mlx, real_map->win, \
				real_map->player, l * 64, h * 64);
			}
			if (real_map->map[h][l] == 'C')
			{
				mlx_put_image_to_window(real_map->mlx, real_map->win, \
				real_map->collect, l * 64, h * 64);
			}
			if (real_map->map[h][l] == 'E')
			{
				mlx_put_image_to_window(real_map->mlx, real_map->win, \
				real_map->exit, l * 64, h * 64);
			}
			l++;
		}
		h++;
	}
}

void	ft_floor(t_map *real_map, t_sarabun *sarabun)
{
	int	h;
	int	l;

	h = 0;
	l = 0;
	while (real_map->map[h])
	{
		l = 0;
		while (real_map->map[h][l] != '\0' && real_map->map[h][l] != '\n')
		{
			if (real_map->map[h][l] == '\n')
				l++;
			mlx_put_image_to_window(real_map->mlx, real_map->win, \
			real_map->floor, l * 64, h * 64);
			l++;
		}
		h++;
	}
}

void	ft_free_render(t_map *real_map)
{
	int	x;

	x = 0;
	while (real_map->map[x] != NULL)
	{
		free(real_map->map[x]);
		x++;
	}
	free(real_map->map);
	free(real_map);
	exit(1);
}
