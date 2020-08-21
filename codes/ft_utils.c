/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:08:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/21 16:15:30 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	putnchar(char chr, size_t len)
{
	size_t	idx;

	idx = 0;
	if (len == 0)
		return (0);
	while (len > idx)
	{
		write(1, &chr, 1);
		idx++;
	}
	return (idx);
}
