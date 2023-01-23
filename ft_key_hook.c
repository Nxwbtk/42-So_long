/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:54:27 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/23 23:14:03 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walk(t_map *real_map, int *r, int *c, int key_code);
int		test_walk(t_map *real_map, int r, int c);

void	ft_come_hook(t_map *real_map)
{
	real_map->step = 0;
	real_map->take_c = 0;
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
	if (key_code == KEY_ESC)
		ft_close(real_map);
	if (key_code == KEY_LEFT || key_code == KEY_A)
		ft_left(real_map, r, c);
	else if (key_code == KEY_W || key_code == KEY_UP)
		ft_up(real_map, r, c);
	else if (key_code == KEY_D || key_code == KEY_RIGHT)
		ft_right(real_map, r, c);
	else if (key_code == KEY_S || key_code == KEY_DOWN)
		ft_down(real_map, r, c);
}

int	test_walk(t_map *real_map, int r, int c)
{
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
			ft_oak_e(real_map);
		else
		{
			ft_printf("Step : %d\n", real_map->step);
			return (1);
		}
	}
	return (0);
}

void	ft_oak_e(t_map *real_map)
{
	ft_printf("Step : %d\n", real_map->step);
	ft_printf("---EXIT COMPLEATE---\n");
	ft_close(real_map);
}
