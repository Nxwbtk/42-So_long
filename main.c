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

	if (ac != 2)
	{
		ft_printf("Please input file");
		exit(1);
	}
	else if (ac == 2)
	{
		ft_check_ber(av[1], &sarabun);
	}
}
