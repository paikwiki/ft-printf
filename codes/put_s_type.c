/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:09:45 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/21 12:03:45 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_putcounts	calc(size_t arg, size_t width, size_t prcs)
{
	t_putcounts	pcnt;

	pcnt.zero = 0;
	if (arg >= width) // 456
	{
		if (arg >= prcs) // 56
		{
			pcnt.arg = prcs;
			pcnt.space = width >= prcs ? width - prcs : 0; // 5, 6
		}
		else // 4
		{
			pcnt.arg = arg;
			pcnt.space = 0;
		}
	}
	else // 123
	{
		pcnt.arg = arg >= prcs ? prcs : arg;
		pcnt.space = arg >= prcs ? width - prcs : width - arg;
	}
	return (pcnt);
}

size_t	put_s_type(char *arg, t_struct *fields)
{
	size_t		proc_len;
	char		*str;
	t_putcounts	pcnt;


	str = ft_strdup(arg);
	proc_len = ft_strlen(str);
	pcnt = calc(proc_len, fields->width, fields->prcs);

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
