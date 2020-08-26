/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:54:26 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/26 11:16:03 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_putcounts	calc(size_t arg, size_t width, size_t prcs, int is_dot)
{
	t_putcounts	pcnt;

	pcnt.arg = (is_dot == 1 && prcs == 0) ? 2 : arg;
	pcnt.zero = 0;
	if (width > 0 && width > arg)
		pcnt.space = (is_dot == 1 && prcs == 0) ? width - 2 : width - arg;
	else
		pcnt.space = 0;
	return (pcnt);
}

size_t	put_p_type(unsigned long arg, t_struct *note)
{
	char		*str;
	size_t		proc_len;
	t_putcounts	pcnt;

	str = ft_strdup(ft_ultoa_base(arg, HEX_LOWER));
	str = ft_strjoin("0x", str);
	proc_len = ft_strlen(str);
	pcnt = calc(proc_len, note->width, note->prcs, note->is_dot);
	proc_len = (note->is_dot == 1 && note->prcs == 0) ? 2 : pcnt.arg;
	if (note->flag == '-') {
		proc_len += putnchar('0', pcnt.zero);
		write(1, str, pcnt.arg);
		proc_len += putnchar(' ', pcnt.space);
	}
	else {
		proc_len += putnchar(' ', pcnt.space);
		proc_len += putnchar('0', pcnt.zero);
		write(1, str, pcnt.arg);
	}
	return (proc_len);
}
