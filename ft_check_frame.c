/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:07:10 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/16 00:30:42 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_frame(t_sarabun *sb)
{
	int	h;
	int	i;
	int	len_line;

	h = 0;
	i = 0;
	len_line = 0;
	while (sb->map[h])
	{
		help(h, i, sb, len_line);
		h++;
	}
}

void	help(int h, int i, t_sarabun *sb, int len_line)
{
	if (h == 0 || h == (sb->hight - 1))
	{
		while (sb->map[h][i] && sb->map[h][i] != '\n')
		{
			if (sb->map[h][i] != '1')
				error(sb);
			i++;
		}
	}
	else
	{
		len_line = ft_strlen(sb->map[h]) - 1;
		if ((sb->map[h][0] != '1' || sb->map[h][len_line - 1] != '1'))
			error(sb);
	}
}

void	error(t_sarabun *sb)
{
	ft_printf("frame\n");
	ft_printf("Error\n");
	ft_free_map(sb);
	exit(1);
}
