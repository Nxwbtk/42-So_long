/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:17 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/16 02:46:54 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_ber(char *av, t_sarabun *sarabun)
{
	int		fd;

	if (ft_strrchr(av, '.') == NULL)
	{
		free(sarabun);
		ft_printf(">>>File name isn\'t .ber<<<");
		exit(EXIT_SUCCESS);
	}
	if (ft_strncmp(ft_strrchr(av, '.'), ".ber", 5) == 0)
	{
		fd = open(av, O_RDONLY);
		if (fd < 0)
		{
			free(sarabun);
			ft_printf(">>> File cann't read or isn't exist <<<");
			exit(EXIT_SUCCESS);
		}
		ft_get_line(fd, sarabun, av);
	}
	else
	{
		ft_printf(">>>File name is wrong!<<<");
		free(sarabun);
		exit(EXIT_SUCCESS);
	}
}
