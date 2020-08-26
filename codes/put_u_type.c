/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:14:52 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/26 11:16:03 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_putcounts	calc(size_t arg, size_t width, size_t prcs, int is_dot, int is_negative)
{
	t_putcounts	pcnt;

	if (arg >= width) // 456
	{
		pcnt.space = 0;
		pcnt.arg = is_dot == 1 && prcs == 0 ? 0 : arg;
		pcnt.zero = arg >= prcs ? 0 : prcs - arg; // 56
	}
	else // 123
	{
		pcnt.arg = is_dot == 1 && prcs == 0 ? 0 : arg;
		if (arg >= prcs) // 3
		{
			pcnt.zero = 0;
			pcnt.space = width - arg - is_negative;
		}
		else // 12
		{
			pcnt.zero = prcs - arg;
			pcnt.space = width >= prcs ? width - prcs - is_negative : 0;
		}
		pcnt.space += is_dot == 1 && prcs == 0 ? 1 : 0;
	}
	return (pcnt);
}

size_t	put_u_type(unsigned int arg, t_struct *note)
{
	size_t proc_len;
	char	*str;
	int		is_negative;

	t_putcounts	pcnt;

	is_negative = arg < 0 ? 1 : 0;
	str = ft_strdup(ft_uitoa_base(arg, DECIMAL));
	proc_len = ft_strlen(str);
	pcnt = calc(proc_len, note->width, note->prcs, note->is_dot, is_negative);
	proc_len = pcnt.arg;
	if (note->flag == '-')
	{
		proc_len += is_negative > 0 ? putnchar('-', 1) : 0;
		proc_len += putnchar('0', pcnt.zero);
		write(1, str, pcnt.arg);
		proc_len += putnchar(' ', pcnt.space);
	}
	else if (note->flag == '0')
	{
		proc_len += note->is_dot == 0 ? putnchar('-', is_negative) : 0;
		proc_len += note->is_dot == 1 ? putnchar(' ', pcnt.space) : putnchar('0', pcnt.space);
		proc_len += note->is_dot == 1 ? putnchar('-', is_negative) : 0;
		proc_len += putnchar('0', pcnt.zero);
		write(1, str, pcnt.arg);
	}
	else
	{
		proc_len += putnchar(' ', pcnt.space);
		proc_len += is_negative > 0 ? putnchar('-', 1) : 0;
		proc_len += putnchar('0', pcnt.zero);
		write(1, str, pcnt.arg);
	}
	return (proc_len);
}
