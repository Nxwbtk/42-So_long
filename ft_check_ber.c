/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:17 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/16 02:03:19 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_ber(char *av, t_sarabun *sarabun)
{
	int		fd;

	if (ft_strrchr(av, '.') == NULL)
	{
		free(sarabun);
		ft_printf("File is invalid");
		exit(1);
	}
	if (ft_strncmp(ft_strrchr(av, '.'), ".ber", 5) == 0)
	{
		fd = open(av, O_RDONLY);
		if (fd < 0)
		{
			free(sarabun);
			ft_printf("File is invalid");
			exit(1);
		}
		ft_get_line(fd, sarabun, av);
	}
	else
	{
		free(sarabun);
		exit(EXIT_SUCCESS);
	}
}
