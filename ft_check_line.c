/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:08:01 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/14 22:43:20 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_line(char *line, t_sarabun *sarabun)
{
	ft_printf("Error\n");
	ft_free_map(sarabun);
	free(line);
	exit(1);
}

void	ft_check_line(char *line, t_sarabun *sarabun)
{
	static int	c;
	static int	p;
	static int	e;
	int			i;

	i = -1;
	if ((line == NULL && c < 1) || p > 1 || e > 1)
		error_line(line, sarabun);
	while (line && line[++i])
	{
		if (ft_strchr("01CPE\n", line[i]) == NULL)
		{
			ft_free_map(sarabun);
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
	sarabun->num_c_can_read = c;
}
