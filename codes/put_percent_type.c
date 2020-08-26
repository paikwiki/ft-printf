/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:51:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/26 11:16:03 by cbaek            ###   ########.fr       */
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

size_t 				put_percent_type(t_struct *note)
{
	size_t		proc_len;
	t_putcounts	pcnt;

	proc_len = 1;
	pcnt = calc(proc_len, note->width);
	if (note->flag == '-')
	{
		write(1, "%", pcnt.arg);
		proc_len += putnchar('0', pcnt.zero);
		proc_len += putnchar(' ', pcnt.space);
	}
	else if (note->flag == '0')
	{
		proc_len += putnchar('0', pcnt.space);
		write(1, "%", pcnt.arg);
	}
	else
	{
		proc_len += putnchar(' ', pcnt.space);
		proc_len += putnchar('0', pcnt.zero);
		write(1, "%", pcnt.arg);
	}
	return (proc_len);
}
