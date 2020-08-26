/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 11:54:26 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/26 11:35:04 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calc(int arg, t_struct *note)
{
	note->arg = (note->is_dot == 1 && note->prcs == 0) ? 2 : arg;
	note->zero = 0;
	if (note->width > 0 && note->width > arg)
		note->space = (note->is_dot == 1 && note->prcs == 0) ? note->width - 2 : note->width - arg;
	else
		note->space = 0;
	return ;
}

size_t	put_p_type(unsigned long arg, t_struct *note)
{
	char	*str;
	int		proc_len;

	str = ft_strdup(ft_ultoa_base(arg, HEX_LOWER));
	str = ft_strjoin("0x", str);
	proc_len = ft_strlen(str);
	calc(proc_len, note);
	proc_len = (note->is_dot == 1 && note->prcs == 0) ? 2 : note->arg;
	if (note->flag == '-') {
		proc_len += putnchar('0', note->zero);
		write(1, str, note->arg);
		proc_len += putnchar(' ', note->space);
	}
	else {
		proc_len += putnchar(' ', note->space);
		proc_len += putnchar('0', note->zero);
		write(1, str, note->arg);
	}
	return (proc_len);
}
