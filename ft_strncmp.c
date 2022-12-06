/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:09 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/05 01:16:10 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*sc1;
	unsigned char	*sc2;
	size_t			i;

	i = 0;
	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	while ((sc1[i] != '\0' || sc2[i] != '\0') && (i < n))
	{
		if (sc1[i] != sc2[i])
		{
			return (sc1[i] - sc2[i]);
		}
	i++;
	}
	return (0);
}
