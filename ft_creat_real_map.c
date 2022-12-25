#include "so_long.h"

void	ft_create_real_map(t_map *map_real, t_sarabun *sarabun)
{
	int	i;

	i = 0;
	map_real->map = (char **)malloc(sizeof(char *) * (sarabun->hight + 1));
	if (!map_real->map)
	{
		ft_printf("Error\nMalloc failed");
		free(sarabun->map);
		exit(1);
	}
	while ()
	// printf("Hello");
}
