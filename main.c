/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:15:09 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/21 21:02:29 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_sarabun	sarabun;
	t_map		real_map;

	if (ac != 2)
	{
		ft_printf("Please input file");
		exit(1);
	}
	else if (ac == 2)
	{
		sarabun.hight = 1;
		real_map.walk = 0;
		ft_check_ber(av[1], &sarabun);
	}
}
