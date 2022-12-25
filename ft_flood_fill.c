/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:36:13 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/25 22:40:30 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, t_sarabun *sarabun, int row, int column)
{
	int	hight;

	hight = sarabun->hight;
	if (row < 0 || column < 0 || row > hight - 1 || column > sarabun->len - 1)
		return ;
	if (map[row][column] == '1')
		return ;
	if (map[row][column] == 'C')
		sarabun->num_c++;
	if (map[row][column] == 'E')
		sarabun->num_e++;
	map[row][column] = '1';
	ft_flood_fill(map, sarabun, row + 1, column);
	ft_flood_fill(map, sarabun, row - 1, column);
	ft_flood_fill(map, sarabun, row, column + 1);
	ft_flood_fill(map, sarabun, row, column - 1);
}

void	check_c_e(t_sarabun *sarabun)
{
	if (sarabun->num_c != sarabun->num_c_can_read || sarabun->num_e != 1)
	{
		ft_printf("Path error\n");
		free(sarabun->map);
		exit(1);
	}
}
