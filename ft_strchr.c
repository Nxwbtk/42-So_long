/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 02:07:50 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/05 02:07:51 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	char			*src;
	size_t			s_len;
	unsigned char	cc;

	src = ((char *)s);
	s_len = ft_strlen(src);
	cc = (unsigned char)c;
	if (!c || !s)
		return (src + s_len);
	while (*src)
	{
		if (*src == cc)
			return (src);
		src++;
	}
	return (NULL);
}
