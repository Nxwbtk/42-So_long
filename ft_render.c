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
	for (int x = 0; x < sarabun->hight; x++)
		printf("%s", real_map->map[x]);
	real_map->mlx = mlx_init();
	real_map->win = mlx_new_window(real_map->mlx, (sarabun->len * 64) + 1, \
	(sarabun->hight * 64) + 1, "42Bangkok");
	real_map->wall = mlx_xpm_file_to_image(real_map->mlx, "./img/Armel64.xpm", &sarabun->len, &sarabun->hight);
	int h = 0;
	int	l = 0;
	while (real_map->map[h])
	{
		l = 0;
		while (real_map->map[h][l] != '\0' && real_map->map[h][l] != '\n')
		{
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->wall, l * 64, h * 64);
			l++;
		}
		h++;
	}
	mlx_loop(real_map->mlx);
	int	x = 0;
	while (real_map->map[x] != NULL)
	{
		free(real_map->map[x]);
		x++;
	}
	free(real_map->map);
	printf("\nFreed\n");
	//free(real_map->map);
	free(real_map);
	exit(1);
}
