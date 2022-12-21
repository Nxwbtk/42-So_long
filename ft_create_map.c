/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:42:18 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/21 21:22:38 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(char *av, t_sarabun *sarabun)
{
	int	fd;
	int	high;

	fd = open(av, O_RDONLY);
	sarabun->map = malloc(sizeof(char *) * (sarabun->hight + 1));
	high = 0;
	while (high < sarabun->hight)
	{
		sarabun->map[high] = get_next_line(fd);
		high++;
	}
	sarabun->map[high] = NULL;
	// printf("Test");
	ft_check_frame(sarabun);
	// next is flood fill
	close(fd);
}
