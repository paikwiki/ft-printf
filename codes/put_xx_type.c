/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xx_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaek <cbaek@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:16:33 by cbaek             #+#    #+#             */
/*   Updated: 2020/09/01 21:05:42 by cbaek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	proc_with_flag(char *str, t_note *note)
{
	int		len;

	len = 0;
	if (note->flag == '-')
	{
		len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
		len += putnchar(' ', note->cnt_space);
	}
	else if (note->flag == '0')
	{
		len += note->is_dot == 1 ? putnchar(' ', note->cnt_space) :
			putnchar('0', note->cnt_space);
		len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
	}
	return (len);
}

static void	calc(int len_arg, t_note *note, int arg)
{
	if (len_arg >= note->width)
	{
		note->cnt_space = note->is_dot == 1 && note->prcs == 0 && arg == 0
				&& note->width > 0 ? 1 : 0;
		note->cnt_arg = len_arg;
		note->cnt_arg = note->is_dot == 1 && note->prcs == 0 &&
				arg == 0 ? 0 : len_arg;
		note->cnt_zero = len_arg >= note->prcs ? 0 : note->prcs - len_arg;
	}
	else
	{
		note->cnt_arg = note->is_dot == 1 && note->prcs == 0 &&
				arg == 0 ? 0 : len_arg;
		if (len_arg >= note->prcs)
		{
			note->cnt_zero = note->flag == '0' && note->prcs < 0 ?
					note->width - len_arg : 0;
			note->cnt_space = note->flag == '0' && note->prcs < 0 ? 0 :
					note->width - len_arg;
		}
		else
		{
			note->cnt_zero = note->prcs - len_arg;
			note->cnt_space = note->width >= note->prcs ?
					note->width - note->prcs : 0;
		}
		note->cnt_space += note->is_dot == 1 && note->prcs == 0 &&
				arg == 0 ? 1 : 0;
	}
	return ;
}

size_t		put_xx_type(unsigned int arg, char *base, t_note *note)
{
	int		proc_len;
	char	*str;

	str = ft_uitoa_base(arg, base);
	proc_len = ft_strlen(str);
	calc(proc_len, note, arg);
	proc_len = note->cnt_arg;
	if (note->flag != 0)
		proc_len += proc_with_flag(str, note);
	else
	{
		proc_len += putnchar(' ', note->cnt_space);
		proc_len += putnchar('0', note->cnt_zero);
		write(1, str, note->cnt_arg);
	}
	free(str);
	return (proc_len);
}
