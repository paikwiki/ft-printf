/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xx_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:16:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/26 11:16:03 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_putcounts	calc(size_t arg, size_t width, size_t prcs, int is_dot)
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
		pcnt.arg = (is_dot == 1 && prcs == 0) ? 0 : arg;
		if (arg >= prcs) // 3
		{
			pcnt.zero = 0;
			pcnt.space = (is_dot == 1 && prcs == 0) ? width : width - arg;
		}
		else // 12
		{
			pcnt.zero = prcs - arg;
			pcnt.space = width >= prcs ? width - prcs : 0;
		}

	}
	return (pcnt);
}

size_t	put_xx_type(unsigned int arg, char *base, t_struct *note)
{
	size_t proc_len;
	char	*str;
	char	pad_char;
	t_putcounts	pcnt;

	str = ft_strdup(ft_uitoa_base(arg, base));
	proc_len = ft_strlen(str);
	pcnt = calc(proc_len, note->width, note->prcs, note->is_dot);
	proc_len = note->is_dot == 1 && note->prcs == 0 ? proc_len - 1 : proc_len;
	if (note->is_dot == 1 && note->width == 0 && note->prcs == 0)
		return (0);
	pad_char = note->flag == '0' && note->is_dot == 0 ? '0' : ' ';
	if (note->flag == '-') {
		proc_len += putnchar('0', pcnt.zero);
		write(1, str, pcnt.arg);
		proc_len += putnchar(pad_char, pcnt.space);
	}
	else {
		proc_len += putnchar(pad_char, pcnt.space);
		proc_len += putnchar('0', pcnt.zero);
		write(1, str, pcnt.arg);
	}
	return (proc_len);
}
