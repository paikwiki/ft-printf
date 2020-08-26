/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:47:52 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/26 11:36:36 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc(int arg, t_struct *note)
{
	note->arg = arg;
	note->zero = 0;
	if (note->width > 0 && note->width > arg)
		note->space = note->width - arg;
	else
		note->space = 0;
	return ;
}

size_t		put_c_type(int arg, t_struct *note)
{
	int	proc_len;

	proc_len = 1;
	calc(proc_len, note);
	if (note->flag == '-') {
		write(1, &arg, note->arg);
		proc_len += putnchar('0', note->zero);
		proc_len += putnchar(' ', note->space);
	}
	else {
		proc_len += putnchar(' ', note->space);
		proc_len += putnchar('0', note->zero);
		write(1, &arg, note->arg);
	}
	return (proc_len);
}
