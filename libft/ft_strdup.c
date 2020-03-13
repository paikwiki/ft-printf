/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:12:12 by cbaek             #+#    #+#             */
/*   Updated: 2020/03/05 12:33:16 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicate;
	int		i;

	i = 0;
	while (s1[i] != 0)
		i++;
	if ((duplicate = (char *)malloc(sizeof(char) * i)) == 0)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		duplicate[i] = s1[i];
		i++;
	}
	return (&duplicate[0]);
}
