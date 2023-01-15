/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:41 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/16 02:49:56 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_get_line(t_sarabun *sarabun)
{
	free(sarabun);
	ft_printf("File is empyty\n");
	exit(EXIT_SUCCESS);
}

void	ft_get_line(int fd, t_sarabun *sarabun, char *av)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		error_get_line(sarabun);
	sarabun->len = ft_slen_no_nl(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (sarabun->len != ft_slen_no_nl(line))
		{
			sarabun->hight++;
			free(line);
			break ;
		}
		ft_check_line(line, sarabun);
		sarabun->hight++;
	}
	get_next_line(fd);
	close(fd);
	ft_create_map(av, sarabun);
}
