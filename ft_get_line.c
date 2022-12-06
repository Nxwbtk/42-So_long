/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:41 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/07 01:32:02 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_line(int fd, t_sarabun *sarabun, char *av)
{
	char	*line;

	line = get_next_line(fd);
	sarabun->hight = 0;
	if (line == NULL)
	{
		ft_printf("File is empyty");
		exit(1);
	}
	sarabun->hight++;
	sarabun->len = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (sarabun->len != ft_strlen(line))
		{
			free(line);
			break ;
		}
		// ft_check_line(line);
		sarabun->hight++;
	}
	// ft_create_map(av, sarabun);
	close(fd);
}
