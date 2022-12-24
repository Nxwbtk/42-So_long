/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:41 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/24 21:52:42 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_line(int fd, t_sarabun *sarabun, char *av)
{
	char	*line;

	line = get_next_line(fd);
	sarabun->hight = 1;
	if (line == NULL)
	{
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
		ft_check_line(line);
		sarabun->hight++;
	}
	close(fd);
	ft_create_map(av, sarabun);
}
