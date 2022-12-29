/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:54:27 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/29 17:28:45 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walk(t_map *real_map, int r, int c, int key_code);
void	test_walk(t_map *real_map, int r, int c);

void	ft_come_hook(t_map *real_map)
{
	real_map->step = 0;
	mlx_key_hook(real_map->win, ft_key_hook, real_map);
	return ;
}

int	ft_key_hook(int key_code, t_map *real_map)
{
	int	r;
	int	c;

	r = real_map->p_pos_r;
	c = real_map->p_pos_c;
	// ft_printf("Test ja\n");
	ft_check_walk(real_map, r, c, key_code);
	ft_printf("Key code = %d\n", key_code);
	return (0);
}

void	ft_check_walk(t_map *real_map, int r, int c, int key_code)
{
	if (key_code == 53)
	{
		mlx_destroy_window(real_map->mlx, real_map->win);
		ft_free_render(real_map);
		exit(1);
	}
	if (key_code == 0 || key_code == 123)
	{
		c--;
		// ft_printf("Test\n");
		test_walk(real_map, r, c);
		if (real_map->map[r][c] == '0' || real_map->map[r][c] == 'C' || real_map->map[r][c] == 'E')
		{
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, c * 64, r * 64);
		}
	}
	if (key_code == 13 || key_code == 126)
	{
		ft_printf("r = %d\t", r);
		r = r - 1;
		ft_printf("r = %d\t", r);
		test_walk(real_map, r, c);
		if (real_map->map[r][c] == '0' || real_map->map[r][c] == 'C' || real_map->map[r][c] == 'E')
		{
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, c * 64, r * 64);
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->player, c * 64, r * 64);
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, c * 64, (r + 1) * 64);
		}
	}
	// if (key_code == 2 || key_code == 124)
	// {
	// 	c++;
	// 	if (real_map->map[*r][c] == '0' || real_map->map[r][c] == 'C' || real_map->map[r][c] == 'E')
	// 	{
	// 		mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, c * 64, r * 64);
	// 		mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->player, c * 64, r * 64);
	// 		mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, (c - 1) * 64, r * 64);
	// 	}
	// }
}

void	test_walk(t_map *real_map, int r, int c)
{
	// ft_printf("Test\n");
	if (real_map->map[r][c] != '1' && real_map->map[r][c] != 'E')
	{
		ft_printf("r = %d\n", r);
		real_map->step++;
		if (real_map->map[r][c] == 'C')
		{
			real_map->take_c++;
			real_map->map[r][c] = '0';
		}
		ft_printf("Step : %d\n", real_map->step);
	}
	else if (real_map->map[r][c] == 'E')
	{
		real_map->step++;
		if (real_map->take_c == real_map->c)
		{
			ft_printf("Step : %d\n", real_map->step);
			ft_free_render(real_map);
			exit(0);
		}
	}
}