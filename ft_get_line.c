/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:41 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/06 06:16:11 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_line(int fd, t_sarabun *sarabun, char *av)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		free(sarabun);
		ft_printf("File is empyty");
		exit(1);
	}
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
