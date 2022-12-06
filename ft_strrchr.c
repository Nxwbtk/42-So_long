/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 01:16:29 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/05 01:16:30 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	c = (unsigned char)c;
	while (s_len >= 0)
	{
		if (s[s_len] == c)
			return ((char *)&s[s_len]);
		s_len--;
	}
	return (0);
}
