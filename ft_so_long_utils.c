/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:28:42 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/24 22:28:10 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_slen_no_nl(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			i++;
		count++;
		i++;
	}
	return (count);
}

// int main(int argc, char const *argv[])
// {
// 	char	test[] = "Test\nTest";
// 	ft_slen_no_nl(test);
// 	return 0;
// }