/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:07:10 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/21 21:22:58 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_frame(t_sarabun *sarabun)
{
	int	h;
	int	i;
	int	len_line;

	h = 0;
	i = 0;
	len_line = 0;
	while (sarabun->map[h])
	{
		if (h == 0 || h == (sarabun->hight - 1))
		{
			while (sarabun->map[h][i])
			{
				if (sarabun->map[h][i] != '1' || sarabun->map[h][i] != '\n')
				{
					exit(1);
				}
				i++;
			}
		}
		else
		{
			len_line = ft_strlen(sarabun->map[h]);
			if (sarabun->map[h][0] != '1' || sarabun->map[h][len_line - 1] != '1')
			{
				exit(1);
			}
		}
		h++;
	}
}