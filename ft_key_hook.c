/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:54:27 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/30 04:12:12 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walk(t_map *real_map, int *r, int *c, int key_code);
int		test_walk(t_map *real_map, int r, int c);

void	ft_come_hook(t_map *real_map)
{
	real_map->step = 0;
	mlx_key_hook(real_map->win, ft_key_hook, real_map);
	return ;
}

int	ft_key_hook(int key_code, t_map *real_map)
{
	static int	r = -1;
	static int	c = -1;
	
	if (r == -1)
	{
		r = real_map->p_pos_r;
		c = real_map->p_pos_c;
	}
	ft_check_walk(real_map, &c, &r, key_code);
	return (0);
}

void	ft_check_walk(t_map *real_map, int *r, int *c, int key_code)
{
	if (key_code == 53)
		ft_close(real_map);
	if (key_code == 0 || key_code == 123)
	{
		if (test_walk(real_map, (*r) - 1, (*c)))
		{
			(*r)--;
			printf("r - 1\n");
			ft_dern(real_map, *r, *c);
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, ((*r) + 1) * 64, \
			((*c))* 64);
		}
	}
	else if (key_code == 13 || key_code == 126)
	{
		if (test_walk(real_map, (*r), (*c) - 1))
		{
			(*c)--;
			ft_dern(real_map, *r, *c);
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, ((*r)) * 64, \
			((*c) + 1) * 64);
		}
	}
	else if (key_code == 2 || key_code == 124)
	{
		if (test_walk(real_map, (*r) + 1, (*c)))
		{
			(*r)++;
			ft_dern(real_map, *r, *c);
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, ((*r) - 1) * 64, \
			((*c)) * 64);
		}
	}
	else if (key_code == 1 || key_code == 125)
	{
		if (test_walk(real_map, (*r), (*c) + 1))
		{
			(*c)++;
			ft_dern(real_map, *r, *c);
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, (*r) * 64, \
			((*c) - 1) * 64);
		}
	}
}

int	test_walk(t_map *real_map, int r, int c)
{
	printf("walk\n");
	if (r > -1 && c > -1 && real_map->map[c][r] != '1' 
		&& real_map->map[c][r] != 'E' )
	{
		real_map->step++;
		if (real_map->map[c][r] == 'C')
		{
			real_map->take_c++;
			real_map->map[c][r] = '0';
		}
		ft_printf("Step : %d\n", real_map->step);
		return (1);
	}
	else if (r > -1 && c > -1 && real_map->map[c][r] == 'E')
	{
		real_map->step++;
		if (real_map->take_c == real_map->c)
		{
			ft_printf("Step : %d\n", real_map->step);
			ft_free_render(real_map);
			exit(0);
		}
	}
	return (0);
}
