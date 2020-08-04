/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 22:52:20 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/03 02:19:40 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dlen;
	size_t slen;
	size_t vacancy;

	dlen = getlen(dst);
	slen = getlen((char *)src);

	if (!dst || !src)
		return (0);
	if (dlen >= dstsize || dstsize == 0)
		return (slen + dstsize);
	i = 0;
	vacancy = dstsize - dlen;
	while (vacancy > 1 && src[i] != 0)
	{
		dst[dlen + i] = src[i];
		i++;
		vacancy--;
	}
	dst[dlen + i] = 0;
	return (dlen + slen);
}
