/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:08:01 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/05 22:33:57 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_line(char *line)
{
	static int	c;
	static int	p;
	static int	e;
	int			i;

	i = -1;
	if ((line == NULL && c < 1) || p > 1 || e > 1)
	{
		free(line);
		exit(1);
	}
	while (line && line[++i])
	{
		if (ft_strchr("01CPE", line[i]) == NULL)
		{
			free(line);
			exit(1);
		}
		if (line[i] == 'C')
			c++;
		if (line[i] == 'P')
			p++;
		if (line[i] == 'E')
			e++;
	}
}
