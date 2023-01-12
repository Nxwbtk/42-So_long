/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:15:09 by bsirikam          #+#    #+#             */
/*   Updated: 2023/01/13 04:21:38 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_sarabun	*sarabun;
	t_map		real_map;

	sarabun = (t_sarabun *)malloc(sizeof(t_sarabun));
	sarabun->hight = 1;
	real_map.step = 0;
	real_map.r_decoy = 0;
	real_map.c_decoy = 0;
	if (ac != 2)
	{
		free(sarabun);
		ft_printf("Please input file");
		exit(1);
	}
	else if (ac == 2)
	{
		ft_check_ber(av[1], sarabun);
	}
}
