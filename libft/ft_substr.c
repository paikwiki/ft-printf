/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 11:19:53 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/06 12:01:33 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	templen;
	size_t	size;

	templen = ft_strlen(s);
	if (templen <= start || len == 0)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	if (templen - start > (size_t)len)
		size = (size_t)len;
	else
		size = templen - start;
	str = (char *)malloc(sizeof(char) * (size + 1));
	templen = 0;
	while (size > 0)
	{
		str[templen++] = s[start++];
		size--;
	}
	str[start] = 0;
	return (str);
}
