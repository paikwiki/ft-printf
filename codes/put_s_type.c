/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:09:45 by cbaek             #+#    #+#             */
/*   Updated: 2020/08/27 16:05:14 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
static void	calc(int arg, t_struct *note)
{
	note->zero = 0;
	if (arg >= note->width) // 456
	{
		if (note->is_dot == 1 && arg >= note->prcs) // 56
		{
			note->arg = note->prcs < 0 ? arg : note->prcs;
			note->space = note->width >= note->prcs && note->prcs >= 0 ? note->width - note->prcs : 0; // 5, 6
		}
		else // 4
		{
			note->arg = arg;
			note->space = 0;
		}
	}
	else // 123
	{
		note->arg = (arg >= note->prcs) && note->prcs > 0 ? note->prcs : arg;
		if (note->prcs < 0)
			note->space = note->width - note->arg;
		else
			note->space = (arg >= note->prcs) && note->is_dot != 0 ? note->width - note->prcs : note->width - arg;
	}
	return ;
}

size_t		put_s_type(char *arg, t_struct *note)
{
	int		proc_len;
	char	*str;

	if (arg == NULL)
		str = ft_strdup(PRINT_NULL);
	else
		str = ft_strdup(arg);
	proc_len = ft_strlen(str);
	calc(proc_len, note);
	note->arg = (note->is_dot == 1 && note->prcs == 0) ? 0 : note->arg;
	proc_len = note->arg;
	if (note->is_dot == 1 && note->width == 0 && note->prcs == 0)
		return (0);
	if (note->flag == '-') {
		write(1, str, note->arg);
		proc_len += putnchar('0', note->zero);
		proc_len += putnchar(' ', note->space);
	}
	else {
		proc_len += putnchar(' ', note->space);
		proc_len += putnchar('0', note->zero);
		write(1, str, note->arg);
	}
	free(str);
	return (proc_len);
}
