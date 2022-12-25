/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:36:13 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/25 16:38:34 by bsirikam         ###   ########.fr       */
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
	map[row][column] = '1';
	ft_flood_fill(map, sarabun, hight, row + 1, column);
	ft_flood_fill(map, sarabun, hight, row - 1, column);
	ft_flood_fill(map, sarabun, hight, row, column + 1);
	ft_flood_fill(map, sarabun, hight, row, column - 1);
}
