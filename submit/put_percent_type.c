/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:51:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/27 23:01:54 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc(int arg, t_note *note)
{
	note->cnt_arg = arg;
	note->cnt_zero = 0;
	if (note->width > 0 && note->width > arg)
		note->cnt_space = note->width - arg;
	else
		note->cnt_space = 0;
	return ;
}

size_t		put_percent_type(t_note *note)
{
	int	proc_len;

	proc_len = 1;
	calc(proc_len, note);
	if (note->flag == '-')
	{
		write(1, "%", note->cnt_arg);
		proc_len += putnchar('0', note->cnt_zero);
		proc_len += putnchar(' ', note->cnt_space);
	}
	else if (note->flag == '0')
	{
		proc_len += putnchar('0', note->cnt_space);
		write(1, "%", note->cnt_arg);
	}
	else
	{
		proc_len += putnchar(' ', note->cnt_space);
		proc_len += putnchar('0', note->cnt_zero);
		write(1, "%", note->cnt_arg);
	}
	return (proc_len);
}
