/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:54:26 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/21 11:33:26 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_putcounts	calc(size_t arg, size_t w)
{
	t_putcounts	pcnt;

	pcnt.arg = arg;
	pcnt.zero = 0;
	if (w > 0 && w > arg)
		pcnt.space = w - arg;
	else
		pcnt.space = 0;
	return (pcnt);
}

size_t	put_p_type(unsigned long arg, t_struct *fields)
{
	char		*str;
	size_t		proc_len;
	t_putcounts	pcnt;

	str = ft_strdup(ft_ultoa_base(arg, HEX_LOWER));
	str = ft_strjoin("0x", str);
	proc_len = ft_strlen(str);
	pcnt = calc(proc_len, fields->width);
	if (fields->flag == '-') {
		write(1, str, pcnt.arg);
		proc_len += putnchar('0', pcnt.zero);
		proc_len += putnchar(' ', pcnt.space);
	}
	else {
		proc_len += putnchar(' ', pcnt.space);
		proc_len += putnchar('0', pcnt.zero);
		write(1, str, pcnt.arg);
	}
	return (proc_len);
}
