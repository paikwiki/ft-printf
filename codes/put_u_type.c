/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:14:52 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/21 13:05:00 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_putcounts	calc(size_t arg, size_t width, size_t prcs)
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
			pcnt.space = width - arg;
		}
		else // 12
		{
			pcnt.zero = prcs - arg;
			pcnt.space = width >= prcs ? width - prcs : 0;
		}

	}
	return (pcnt);
}

size_t	put_u_type(unsigned int arg, t_struct *fields)
{
	size_t proc_len;
	char	*str;
	char	pad_char;
	t_putcounts	pcnt;

	str = ft_strdup(ft_uitoa_base(arg, DECIMAL));
	proc_len = ft_strlen(str);
	pcnt = calc(proc_len, fields->width, fields->prcs);
	pad_char = fields->flag == '0' ? '0' : ' ';
	if (fields->flag == '-') {
		write(1, str, pcnt.arg);
		proc_len += putnchar('0', pcnt.zero);
		proc_len += putnchar(pad_char, pcnt.space);
	}
	else {
		proc_len += putnchar(pad_char, pcnt.space);
		proc_len += putnchar('0', pcnt.zero);
		write(1, str, pcnt.arg);
	}
	return (ft_strlen(str));
}
