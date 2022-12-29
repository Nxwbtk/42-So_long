#include "so_long.h"

void	ft_check_walk(t_map *real_map, int r, int c, int key_code);

void	ft_come_hook(t_map *real_map)
{
	mlx_key_hook(real_map->win, ft_key_hook, real_map);
	return ;
}

int	ft_key_hook(int key_code, t_map *real_map)
{
	int	r;
	int	c;

	r = real_map->p_pos_r;
	c = real_map->p_pos_c;
	ft_check_walk(real_map, r, c, key_code);
	printf("%d\n", key_code);
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
		if (real_map->map[r][c] == '0' || real_map->map[r][c] == 'C' || real_map->map[r][c] == 'E')
		{
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, c * 64, r * 64);
		}
	}
	if (key_code == 13 || key_code == 126)
	{
		r--;
		if (real_map->map[r][c] == '0' || real_map->map[r][c] == 'C' || real_map->map[r][c] == 'E')
		{
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, c * 64, r * 64);
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->player, c * 64, r * 64);
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, c * 64, (r + 1) * 64);
		}
	}
	if (key_code == 2 || key_code == 124)
	{
		c++;
		if (real_map->map[r][c] == '0' || real_map->map[r][c] == 'C' || real_map->map[r][c] == 'E')
		{
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, c * 64, r * 64);
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->player, c * 64, r * 64);
			mlx_put_image_to_window(real_map->mlx, real_map->win, real_map->floor, (c - 1) * 64, r * 64);
		}
	}
}