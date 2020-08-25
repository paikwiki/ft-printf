/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 10:08:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/25 22:39:52 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_abs(int arg)
{
	unsigned int	value;

	value = arg > 0 ? (unsigned int)arg : (unsigned int)arg * -1;
	return (ft_uitoa_base(value, DECIMAL));
}

size_t	putnchar(char chr, size_t len)
{
	size_t			idx;

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
