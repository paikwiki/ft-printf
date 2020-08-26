/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:09:45 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/26 11:16:03 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static t_putcounts	calc(size_t arg, size_t width, size_t prcs, int is_dot)
{
	t_putcounts	pcnt;

	pcnt.zero = 0;
	if (arg >= width) // 456
	{
		if (is_dot == 1 && arg >= prcs) // 56
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
		pcnt.arg = (arg >= prcs && prcs != 0) ? prcs : arg;
		pcnt.space = (arg >= prcs && is_dot != 0) ? width - prcs : width - arg;
	}
	return (pcnt);
}

size_t	put_s_type(char *arg, t_struct *note)
{
	size_t		proc_len;
	char		*str;
	t_putcounts	pcnt;

	if (arg == NULL)
		str = ft_strdup(PRINT_NULL);
	else
		str = ft_strdup(arg);
	proc_len = ft_strlen(str);
	pcnt = calc(proc_len, note->width, note->prcs, note->is_dot);
	pcnt.arg = (note->is_dot == 1 && note->prcs == 0) ? 0 : pcnt.arg;
	proc_len = pcnt.arg;
	if (note->is_dot == 1 && note->width == 0 && note->prcs == 0)
		return (0);
	if (note->flag == '-') {
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
