/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:28:53 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/07 21:09:34 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	setstrs_mem(char **strs, char *s, char c)
{
	int i;
	int cnt;
	int strlen;

	i = 0;
	cnt = 0;
	strlen = 0;
	while(s[i] == c)
		i++;
	while (s[i] != 0)
	{
		if((s[i - 1] != c && s[i] == c) || (s[i + 1] == 0 && s[i] != c))
		{
			strs[cnt++] = (char *)malloc(sizeof(char) * (strlen + 1));
			strlen = 0;
		}
		else
			if (s[i] != c)
				strlen++;
		i++;
	}
}

static void	setstrs_str(char **strs, char *s, char c, size_t i)
{
	int	cnt;
	int	strlen;

	cnt = 0;
	strlen = 0;
	while(s[i] == c)
		i++;
	while (s[i] != 0)
	{
		if ((s[i] != c) && (s[i + 1] != 0))
			strs[cnt][strlen++] = s[i];
		else if (s[i - 1] != c && s[i] == c)
		{
			strs[cnt++][strlen + 1] = 0;
			strlen = 0;
		}
		else if (s[i + 1] == 0 && s[i] != c)
		{
			strs[cnt][strlen] = s[i];
			strs[cnt][strlen + 1] = 0;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while(s[i] == c)
		i++;
	while (s[i] != 0)
	{
		if((s[i - 1] != c && s[i] == c) || (s[i + 1] == 0 && s[i] != c))
			cnt++;
		i++;
	}
	strs = (char **)malloc(sizeof(char *) * (cnt + 1));
	strs[cnt] = 0;
	setstrs_mem(strs, (char *)s, c);
	setstrs_str(strs, (char *)s, c, 0);
	return (strs);
}
