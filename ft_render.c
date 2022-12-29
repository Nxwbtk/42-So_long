/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:39:04 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/30 02:48:05 by bsirikam         ###   ########.fr       */
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
	real_map->floor = mlx_xpm_file_to_image(real_map->mlx, \
	"./img/floor64.xpm", &sarabun->len, &sarabun->hight);
	real_map->player = mlx_xpm_file_to_image(real_map->mlx, \
	"./img/Armel64.xpm", &sarabun->len, &sarabun->hight);
	real_map->collect = mlx_xpm_file_to_image(real_map->mlx, \
	"./img/collect.xpm", &sarabun->len, &sarabun->hight);
	real_map->exit = mlx_xpm_file_to_image(real_map->mlx, "./img/Exit64.xpm", \
	&sarabun->len, &sarabun->hight);
	ft_floor(real_map, sarabun);
	ft_wall(real_map);
	real_map->p_pos_r = sarabun->p_pos_r;
	real_map->p_pos_c = sarabun->p_pos_c;
	real_map->c = sarabun->num_c_can_read;
	real_map->height = sarabun->hight;
	ft_come_hook(real_map);
	mlx_loop(real_map->mlx);
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
			ft_put_img(real_map->map[h][l], real_map, h, l);
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

void	ft_put_img(char c, t_map *real_map, int h, int l)
{
	if (c == '1')
	{
		mlx_put_image_to_window(real_map->mlx, real_map->win, \
		real_map->wall, l * 64, h * 64);
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(real_map->mlx, real_map->win, \
		real_map->player, l * 64, h * 64);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(real_map->mlx, real_map->win, \
		real_map->collect, l * 64, h * 64);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(real_map->mlx, real_map->win, \
		real_map->exit, l * 64, h * 64);
	}
}
