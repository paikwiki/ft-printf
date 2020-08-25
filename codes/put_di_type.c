/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_di_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:13:28 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/25 22:58:38 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_putcounts	calc(size_t arg, size_t width, size_t prcs, int is_negative)
{
	t_putcounts	pcnt;

	if (arg >= width) // 456
	{
		pcnt.space = 0;
		pcnt.arg = arg;
		pcnt.zero = arg >= prcs ? 0 : prcs - arg; // 56
	}
	else // 123
	{
		pcnt.arg = arg;
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

	}
	return (pcnt);
}

size_t	put_di_type(int arg, t_struct *fields)
{
	size_t proc_len;
	char	*str;
	int		is_negative;
	// int		pad_char;

	t_putcounts	pcnt;

	is_negative = arg < 0 ? 1 : 0;
	str = ft_strdup(itoa_abs(arg));
	proc_len = ft_strlen(str);
	pcnt = calc(proc_len, fields->width, fields->prcs, is_negative);
	// pad_char = fields->flag == '0' ? '0' : ' ';
	if (fields->flag == '-')
	{
		proc_len += is_negative > 0 ? putnchar('-', 1) : 0;
		proc_len += putnchar('0', pcnt.zero);
		write(1, str, pcnt.arg);
		proc_len += putnchar(' ', pcnt.space);
	}
	else if (fields->flag == '0')
	{
		// proc_len += putnchar(pad_char, pcnt.space);
		proc_len += is_negative > 0 ? putnchar('-', 1) : 0;
		proc_len += putnchar('0', pcnt.zero + pcnt.space);
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
