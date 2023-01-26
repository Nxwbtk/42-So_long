/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:08:01 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/27 01:44:57 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_line(char *line, t_sarabun *sarabun)
{
	ft_printf("Line Error. Doesn\'t have C or P or E or 1 following the rule.\n");
	free(line);
	free(sarabun->map);
	free(sarabun);
	exit(EXIT_SUCCESS);
}

void	ft_strchr_bruh(t_sarabun *sarabun, char *line)
{
	free(sarabun);
	free(line);
	ft_printf("Line Error. Doesn\'t have C or P or E or 1 following the rule.\n");
	exit(EXIT_SUCCESS);
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
			ft_strchr_bruh(sarabun, line);
		if (line[i] == 'C')
			c++;
		if (line[i] == 'P')
			p++;
		if (line[i] == 'E')
			e++;
	}
	sarabun->num_c_can_read = c;
}
