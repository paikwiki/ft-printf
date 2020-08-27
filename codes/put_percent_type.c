/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_percent_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:51:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/27 20:04:54 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc(int arg, t_note *note)
{
	note->arg = arg;
	note->zero = 0;
	if (note->width > 0 && note->width > arg)
		note->space = note->width - arg;
	else
		note->space = 0;
	return ;
}

size_t 		put_percent_type(t_note *note)
{
	int	proc_len;

	proc_len = 1;
	calc(proc_len, note);
	if (note->flag == '-')
	{
		write(1, "%", note->arg);
		proc_len += putnchar('0', note->zero);
		proc_len += putnchar(' ', note->space);
	}
	else if (note->flag == '0')
	{
		proc_len += putnchar('0', note->space);
		write(1, "%", note->arg);
	}
	else
	{
		proc_len += putnchar(' ', note->space);
		proc_len += putnchar('0', note->zero);
		write(1, "%", note->arg);
	}
	return (proc_len);
}
